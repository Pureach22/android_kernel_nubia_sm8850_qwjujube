__int64 __fastcall sub_623938(
        int a1,
        int a2,
        int a3,
        int a4,
        void *a5,
        int a6,
        int a7,
        __int64 a8,
        __int16 a9,
        __int16 a10,
        __int64 a11)
{
  __arm_mte_set_tag((void *)(a8 + 96), a5);
  return tgt_dfs_set_current_channel_for_freq(a1, a2, a3, a4, (int)a5, a6, a7, a8, a9, a10, a11);
}
