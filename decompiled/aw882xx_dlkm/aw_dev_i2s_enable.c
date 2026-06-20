__int64 __fastcall aw_dev_i2s_enable(__int64 a1, char a2)
{
  unsigned int v2; // w8
  _DWORD *v3; // x10
  __int64 v4; // x9
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 *v8; // x8
  __int64 v9; // x1

  v2 = *(_DWORD *)(a1 + 424);
  if ( v2 == 255 )
  {
    v8 = *(__int64 **)(a1 + 112);
    v9 = v8[14];
    if ( !v9 )
      v9 = *v8;
    return printk(&unk_27FF7, v9, "aw_dev_i2s_enable");
  }
  else
  {
    if ( (a2 & 1) != 0 )
    {
      v3 = *(_DWORD **)(a1 + 1168);
      v4 = *(_QWORD *)(a1 + 120);
      v5 = *(unsigned int *)(a1 + 428);
      if ( *(_BYTE *)(a1 + 649) )
        v6 = *(unsigned int *)(a1 + 432);
      else
        v6 = *(unsigned int *)(a1 + 440);
    }
    else
    {
      v3 = *(_DWORD **)(a1 + 1168);
      v4 = *(_QWORD *)(a1 + 120);
      v5 = *(unsigned int *)(a1 + 428);
      v6 = *(unsigned int *)(a1 + 436);
    }
    if ( *(v3 - 1) != 370515439 )
      __break(0x822Au);
    return ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64))v3)(v4, v2, v5, v6);
  }
}
