#include "cache.h"
#include "bits.h"

address_type get_set(Cache *cache, address_type address) {
  /* TODO:
     Extract the set bits from a 64-bit address.
  */

     int tag = 64 - (cache->set_bits + cache->block_bits);

  return (address<<tag)>>(tag + cache->block_bits);
}

address_type get_line(Cache *cache, address_type address) {
  /* TODO:
     Extract the tag bits from a 64-bit address.
  */

  return address>>(cache->set_bits + cache->block_bits);
}

address_type get_byte(Cache *cache, address_type address) {
  /* TODO
     Extract the block (byte index) bits from a 64-bit address.
  */
     int tag = 64 - (cache->set_bits + cache->block_bits);
  return (address<<(tag + cache->set_bits))>>(tag + cache->set_bits);
}
