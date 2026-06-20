__int64 __fastcall sub_4C4660(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        void *a8)
{
  __int64 v8; // x12

  __arm_mte_set_tag((void *)(v8 - 1328), a8);
  return dp_get_vdev_param();
}
