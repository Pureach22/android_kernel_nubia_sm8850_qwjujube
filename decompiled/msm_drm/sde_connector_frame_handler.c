__int64 __fastcall sde_connector_frame_handler(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 v4; // x8
  int v5; // w1
  unsigned int v6; // w2
  __int64 v9; // x8
  unsigned __int64 v10; // x2
  int v11; // w1

  if ( a1 && (v2 = *(_QWORD *)(a1 + 328)) != 0 && (v3 = *(_QWORD *)(v2 + 8)) != 0 )
  {
    if ( *(_DWORD *)(v3 + 2736) == 16 )
    {
      v4 = *(_QWORD *)(v3 + 2512);
      if ( v4 )
      {
        v5 = *(_DWORD *)(v4 + 1984);
        v6 = *(_DWORD *)(v4 + 2016);
      }
      else
      {
        v5 = 0;
        v6 = 0;
      }
      sde_sync_aod_and_fod(a1, v5, v6);
      v9 = *(_QWORD *)(v3 + 2512);
      if ( v9 )
      {
        v10 = *(_QWORD *)(v9 + 1344);
        v11 = (*(_DWORD *)(v9 + 2016) >> 2) & 1;
      }
      else
      {
        v11 = 0;
        v10 = 0;
      }
      sde_sync_sdr_dim(a1, v11, v10);
    }
    return 0;
  }
  else
  {
    printk(&unk_24E60A, a2);
    return 4294967274LL;
  }
}
