__int64 __fastcall btfmcodec_wq_hwep_configure(__int64 a1)
{
  __int64 v1; // x20
  _QWORD *v3; // x21
  _QWORD **v4; // x28
  unsigned int v5; // w23
  unsigned int v6; // w24
  _QWORD *v7; // x22
  unsigned int v8; // w25
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 (**v11)(void); // x8
  __int64 (*v12)(void); // x8
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 (*v16)(void); // x8
  char v17; // w8
  _QWORD *v19; // x24
  _QWORD *v20; // x25
  int v21; // w0

  v1 = *(_QWORD *)(a1 + 288);
  v3 = *(_QWORD **)(v1 + 992);
  v4 = (_QWORD **)(v1 + 992);
  if ( v3 == (_QWORD *)(v1 + 992) )
  {
    v17 = 1;
  }
  else
  {
    while ( 1 )
    {
      v5 = *((unsigned __int8 *)v3 - 24);
      v6 = *((_DWORD *)v3 - 5);
      v7 = (_QWORD *)*v3;
      v8 = *((_DWORD *)v3 - 3);
      printk(&unk_CBF9, "btfmcodec_wq_hwep_configure");
      v9 = *(_QWORD *)(v1 + 984);
      if ( !v9 )
        break;
      v10 = *(_QWORD *)(v9 + 80);
      if ( !v10 )
        break;
      v11 = *(__int64 (***)(void))(v10 + 112);
      if ( !v11 )
        break;
      v12 = *v11;
      if ( !v12 )
        break;
      if ( *((_DWORD *)v12 - 1) != -1066802076 )
        __break(0x8228u);
      if ( (v12() & 0x80000000) != 0 )
        break;
      v13 = *(_QWORD *)(v1 + 984);
      if ( !v13 )
        break;
      v14 = *(_QWORD *)(v13 + 80);
      if ( !v14 )
        break;
      v15 = *(_QWORD *)(v14 + 112);
      if ( !v15 )
        break;
      v16 = *(__int64 (**)(void))(v15 + 16);
      if ( !v16 )
        break;
      if ( *((_DWORD *)v16 - 1) != 851138883 )
        __break(0x8228u);
      if ( (v16() & 0x80000000) != 0 || (btfmcodec_hwep_prepare(v1, v6, v8, v5, 1) & 0x80000000) != 0 )
        break;
      v17 = 1;
      *((_BYTE *)v3 - 7) = 1;
      v3 = v7;
      if ( v7 == v4 )
        goto LABEL_20;
    }
    *((_BYTE *)v3 - 7) = 1;
    printk(&unk_D8B4, "btfmcodec_wq_hwep_configure");
    v19 = *v4;
    if ( *v4 == v4 )
    {
      v17 = 2;
    }
    else
    {
      do
      {
        v20 = (_QWORD *)*v19;
        if ( *((_BYTE *)v19 - 7) )
        {
          printk(&unk_DBC0, "btfmcodec_wq_hwep_configure");
          v21 = btfmcodec_hwep_shutdown(v1, *((unsigned __int8 *)v19 - 24), 1);
          *((_BYTE *)v19 - 7) = 0;
          if ( v21 < 0 )
            printk(&unk_D2FE, "btfmcodec_wq_hwep_configure");
        }
        v17 = 2;
        v19 = v20;
      }
      while ( v20 != v4 );
    }
  }
LABEL_20:
  *(_BYTE *)(a1 + 285) = v17;
  return _wake_up(a1 + 208, 1, 1, 0);
}
