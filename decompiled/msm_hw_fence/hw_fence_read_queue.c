__int64 __fastcall hw_fence_read_queue(__int64 a1, unsigned int *a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // x30

  if ( a3 && a2 && (int)a4 < 2 )
  {
    if ( a4 >= 3 )
    {
      __break(0x5512u);
      return hw_fence_read_queue_helper();
    }
    else
    {
      if ( (~msm_hw_fence_debug_level & 0x10010) == 0 )
        printk(&unk_2861E, "hw_fence_read_queue", 285, *a2, &a2[12 * a4 + 10]);
      return hw_fence_read_queue_helper();
    }
  }
  else
  {
    printk(&unk_27F9F, "hw_fence_read_queue", 280, v4, a4);
    return 4294967274LL;
  }
}
