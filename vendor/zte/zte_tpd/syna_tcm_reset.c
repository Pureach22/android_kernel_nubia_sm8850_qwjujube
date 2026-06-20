__int64 __fastcall syna_tcm_reset(__int64 a1, unsigned int a2, __int64 a3)
{
  unsigned int v4; // w8
  __int64 v5; // x5
  _DWORD *v6; // x8
  unsigned int v7; // w0
  __int64 (__fastcall *v8)(_QWORD); // x8
  __int64 (__fastcall *v9)(_QWORD); // x8
  __int64 v10; // x0
  unsigned int v11; // w0
  __int64 v12; // x2
  unsigned int v14; // w19
  unsigned int v15; // w20

  if ( a1 )
  {
    if ( a2
      || (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) == 0
      && (v15 = *(_DWORD *)(a1 + 492), printk(unk_3BA3F, "syna_tcm_reset", a3), (a2 = v15) != 0) )
    {
      v4 = *(_DWORD *)(a1 + 492);
      if ( v4 <= a2 )
        v5 = a2;
      else
        v5 = v4;
    }
    else
    {
      v5 = 0;
    }
    v6 = *(_DWORD **)(a1 + 920);
    if ( *(v6 - 1) != 606091918 )
      __break(0x8228u);
    v7 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD, __int64))v6)(a1, 4, 0, 0, 0, v5);
    if ( (v7 & 0x80000000) != 0 )
    {
      v14 = v7;
      printk(unk_39AB7, "syna_tcm_reset", 4);
    }
    else
    {
      v8 = *(__int64 (__fastcall **)(_QWORD))(a1 + 944);
      *(_BYTE *)(a1 + 9) = *(_BYTE *)(a1 + 129);
      if ( v8 )
      {
        if ( *((_DWORD *)v8 - 1) != -713399031 )
          __break(0x8228u);
        v8(a1);
      }
      v9 = *(__int64 (__fastcall **)(_QWORD))(a1 + 9184);
      if ( !v9 )
        return 0;
      v10 = *(_QWORD *)(a1 + 9176);
      if ( *((_DWORD *)v9 - 1) != -1066802076 )
        __break(0x8228u);
      v11 = v9(v10);
      if ( (v11 & 0x80000000) == 0 )
        return 0;
      v14 = v11;
      printk(unk_32B5F, "syna_tcm_reset", v12);
    }
    return v14;
  }
  else
  {
    printk(unk_3365A, "syna_tcm_reset", a3);
    return 4294967055LL;
  }
}
