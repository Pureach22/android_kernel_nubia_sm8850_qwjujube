__int64 __fastcall synx_util_get_object_status(
        unsigned __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 result; // x0
  unsigned __int64 v8; // x0
  unsigned int status; // w0
  unsigned int v10; // w8

  result = 0;
  if ( a1 && a1 <= 0xFFFFFFFFFFFFF000LL )
  {
    v8 = *(_QWORD *)(a1 + 64);
    if ( (*(_BYTE *)(a1 + 124) & 0x20) != 0 )
    {
      return _fence_group_state(v8, 0);
    }
    else if ( v8 && v8 < 0xFFFFFFFFFFFFF001LL )
    {
      status = dma_fence_get_status();
      v10 = status + 6;
      if ( status + 6 < 8 && ((0xCDu >> v10) & 1) != 0 )
      {
        return dword_2BF20[v10];
      }
      else if ( status <= 0xFFFFFFBF )
      {
        return -status;
      }
      else
      {
        return 5;
      }
    }
    else
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_289DC, &unk_29207, "__fence_state", 846, a5, a6);
      return 0;
    }
  }
  return result;
}
