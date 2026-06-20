__int64 __fastcall tpg_1_3_shdr_offset_num_batch_open(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  return simple_attr_open(a1, a2, tpg_1_3_get_shdr_offset_num_batch, tpg_1_3_set_shdr_offset_num_batch, "%16lld", a6);
}
