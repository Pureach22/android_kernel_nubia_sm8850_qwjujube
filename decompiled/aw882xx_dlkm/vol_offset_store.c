__int64 __fastcall vol_offset_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w8
  __int64 *v7; // x8
  __int64 v8; // x1
  __int64 v10; // [xsp+0h] [xbp-10h] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v10 = 0;
  if ( sscanf(s, "%d %d", &v10, (char *)&v10 + 4) == 2 )
  {
    v6 = v10;
    if ( (_DWORD)v10 )
    {
      aw882xx_dsp_write_vol_offset(*(_QWORD *)(v5 + 96), HIDWORD(v10));
      v6 = v10;
    }
    *(_DWORD *)(*(_QWORD *)(v5 + 96) + 68LL) = v6;
    *(_DWORD *)(*(_QWORD *)(v5 + 96) + 72LL) = HIDWORD(v10);
  }
  v7 = *(__int64 **)(v5 + 64);
  v8 = v7[14];
  if ( !v8 )
    v8 = *v7;
  printk(&unk_25CEA, v8, "vol_offset_store");
  _ReadStatusReg(SP_EL0);
  return a4;
}
