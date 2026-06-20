__int64 __fastcall syna_dev_enter_normal_sensing(__int64 *a1)
{
  __int64 v1; // x8
  __int64 v3; // x0
  unsigned int v4; // w20
  unsigned int v5; // w0
  __int64 v6; // x2
  void *v8; // x8
  unsigned int v9; // w19

  v1 = a1[78];
  v3 = *a1;
  if ( *(_DWORD *)(v1 + 184) && (*(_BYTE *)(v1 + 188) & 1) != 0 )
    v4 = 0;
  else
    v4 = *(_DWORD *)(v3 + 524);
  v5 = syna_tcm_sleep(v3, 0, v4);
  if ( (v5 & 0x80000000) != 0 )
  {
    v8 = &unk_37DAD;
    goto LABEL_13;
  }
  if ( *((_BYTE *)a1 + 1409) == 1 )
  {
    v5 = syna_dev_enable_lowpwr_gesture(a1, 0, v4);
    if ( (v5 & 0x80000000) == 0 )
    {
      msleep(100);
      return 0;
    }
    v8 = &unk_37671;
LABEL_13:
    v9 = v5;
    printk(v8, "syna_dev_enter_normal_sensing", v6);
    return v9;
  }
  return 0;
}
