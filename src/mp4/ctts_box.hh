#ifndef CTTS_BOX_HH
#define CTTS_BOX_HH

#include "box.hh"

namespace MP4 {

class CttsBox : public FullBox
{
public:
  struct Entry {
    uint32_t sample_count;
    int64_t sample_offset;
  };

  CttsBox(const uint64_t size, const std::string & type);

  /* accessors */
  uint32_t entry_count() { return entries_.size(); }
  std::vector<Entry> entries() { return entries_; }

  uint32_t total_sample_count();

  /* mutators */
  void set_entries(std::vector<Entry> entries);

  void print_box(const unsigned int indent = 0);

  void parse_data(MP4File & mp4, const uint64_t data_size);
  void write_box(MP4File & mp4);

private:
  /* use int64_t to hold both unsigned and signed int32 */
  std::vector<Entry> entries_;
};

}

#endif /* CTTS_BOX_HH */
