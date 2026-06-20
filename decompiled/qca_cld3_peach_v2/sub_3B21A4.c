__int64 __fastcall sub_3B21A4(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        void *a8)
{
  __int64 v8; // x16

  __arm_mte_set_tag((void *)(v8 - 1376), a8);
  return lim_tspec_add();
}
