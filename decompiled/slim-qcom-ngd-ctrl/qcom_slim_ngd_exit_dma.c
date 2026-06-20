void __fastcall qcom_slim_ngd_exit_dma(__int64 a1)
{
  __int64 v2; // x20
  int v3; // w8
  __int64 v4; // x21
  _QWORD *v5; // x22
  unsigned int (__fastcall *v6)(_QWORD); // x8
  __int64 v7; // x0
  void (__fastcall *v8)(_QWORD); // x8
  __int64 v9; // x21
  unsigned int (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x0
  void (__fastcall *v12)(_QWORD); // x8
  __int64 v13; // x9
  _QWORD *v14; // x10

  v2 = *(_QWORD *)(a1 + 1968);
  _slimbus_dbg();
  v3 = *(_DWORD *)(a1 + 5476);
  if ( v3 >= 3 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 5488), "SLIM: NGD exit dma\n");
    v3 = *(_DWORD *)(a1 + 5476);
  }
  if ( !v3 )
    ipc_log_string(*(_QWORD *)(a1 + 5496), "SLIM: NGD exit dma\n");
  v4 = *(_QWORD *)(a1 + 1984);
  v5 = (_QWORD *)(a1 + 1984);
  if ( v4 )
  {
    v6 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)v4 + 336LL);
    if ( v6 )
    {
      v7 = *(_QWORD *)(a1 + 1984);
      if ( *((_DWORD *)v6 - 1) != -403578064 )
        __break(0x8228u);
      if ( !v6(v7) )
      {
        v8 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)v4 + 344LL);
        if ( v8 )
        {
          if ( *((_DWORD *)v8 - 1) != 905352215 )
            __break(0x8228u);
          v8(v4);
        }
      }
    }
    dma_release_channel(*v5);
  }
  v9 = *(_QWORD *)(a1 + 1992);
  if ( v9 )
  {
    v10 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)v9 + 336LL);
    if ( v10 )
    {
      v11 = *(_QWORD *)(a1 + 1992);
      if ( *((_DWORD *)v10 - 1) != -403578064 )
        __break(0x8228u);
      if ( !v10(v11) )
      {
        v12 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)v9 + 344LL);
        if ( v12 )
        {
          if ( *((_DWORD *)v12 - 1) != 905352215 )
            __break(0x8228u);
          v12(v9);
        }
      }
    }
    dma_release_channel(*(_QWORD *)(a1 + 1992));
  }
  if ( (*(_BYTE *)(a1 + 5468) & 1) != 0 )
  {
    v13 = *(unsigned int *)(a1 + 5464);
    v14 = *(_QWORD **)(a1 + 5440);
    *(_QWORD *)(a1 + 5448) = *(_QWORD *)(a1 + 5456);
    *v14 = v13;
  }
  else
  {
    dma_free_attrs(v2, 1200, *(_QWORD *)(a1 + 5408), *(_QWORD *)(a1 + 5392), 0);
    dma_free_attrs(v2, 1240, *(_QWORD *)(a1 + 5416), *(_QWORD *)(a1 + 5400), 0);
    *(_QWORD *)(a1 + 5416) = 0;
    *(_QWORD *)(a1 + 5408) = 0;
  }
  *v5 = 0;
  *(_QWORD *)(a1 + 1992) = 0;
}
