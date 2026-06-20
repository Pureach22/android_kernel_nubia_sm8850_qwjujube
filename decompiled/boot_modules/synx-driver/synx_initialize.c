unsigned __int64 __fastcall synx_initialize(
        unsigned __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  unsigned __int64 result; // x0
  __int64 v7; // x4
  __int64 v8; // x5
  __int64 *v9; // x8
  unsigned __int64 v10; // x19
  __int64 v11; // x3

  if ( a1 && a1 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( (unsigned int)(*(_DWORD *)(a1 + 16) - 1024) > 0xBFF )
    {
      result = synx_internal_initialize((const char **)a1);
      if ( result && result < 0xFFFFFFFFFFFFF001LL )
      {
        v9 = &synx_internal_ops;
        goto LABEL_13;
      }
      if ( (synx_debug & 1) != 0 )
      {
        v10 = result;
        v11 = 71;
        goto LABEL_19;
      }
    }
    else
    {
      result = synx_hwfence_initialize();
      if ( result && result < 0xFFFFFFFFFFFFF001LL )
      {
        v9 = (__int64 *)&synx_hwfence_ops;
LABEL_13:
        *(_QWORD *)(result + 16) = v9;
        return result;
      }
      if ( (synx_debug & 1) != 0 )
      {
        v10 = result;
        v11 = 64;
LABEL_19:
        printk(&unk_28B09, &unk_29207, "synx_initialize", v11, v7, v8);
        return v10;
      }
    }
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2A5F2, &unk_29207, "synx_initialize", 57, a5, a6);
    return -22;
  }
  return result;
}
