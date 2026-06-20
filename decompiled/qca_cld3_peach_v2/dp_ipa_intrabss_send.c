__int64 __fastcall dp_ipa_intrabss_send(__int64 a1, __int64 a2, __int64 a3, _BYTE *a4)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x19
  char v18; // w26
  __int64 v19; // x25
  int v20; // w8
  __int64 v21; // x0
  unsigned int v22; // w22
  __int64 (*v23)(void); // x8
  char v24; // w8
  _DWORD *v25; // x8
  __int64 v26; // x5
  __int64 *v27; // x0
  __int64 v28; // x8

  _ReadStatusReg(SP_EL0);
  result = dp_vdev_bss_peer_ref_n_get(*(_QWORD *)(a1 + 8), a2, 0xEu);
  if ( result )
  {
    v17 = result;
    if ( *(_QWORD *)result )
    {
      *a4 = 0;
      v18 = *(_BYTE *)(a3 + 41);
      v19 = *(_QWORD *)(**(_QWORD **)result + 24LL);
      qdf_mem_set((void *)(a3 + 40), 0x30u, 0);
      v20 = 0;
      if ( (*(_BYTE *)(a3 + 68) & 4) != 0 )
        v20 = *(unsigned __int16 *)(a3 + 66);
      v21 = *(_QWORD *)(a1 + 8);
      v22 = *(_DWORD *)(a3 + 112) + v20;
      if ( (v18 & 2) == 0 )
        goto LABEL_15;
      v23 = *(__int64 (**)(void))(v21 + 1680);
      if ( !v23 )
        goto LABEL_15;
      if ( *((_DWORD *)v23 - 1) != 2007598513 )
        __break(0x8228u);
      v24 = v23();
      v21 = *(_QWORD *)(a1 + 8);
      if ( (v24 & 1) != 0 )
      {
        v25 = *(_DWORD **)(v21 + 1672);
        if ( v25 )
        {
          v26 = *(_QWORD *)v17;
          if ( *(v25 - 1) != -556669357 )
            __break(0x8228u);
          if ( (((__int64 (__fastcall *)(_QWORD, _QWORD, __int64, _QWORD, _QWORD, __int64, __int64))v25)(
                  0,
                  0,
                  a3,
                  0,
                  v22,
                  v26,
                  v19 + 42680)
              & 1) != 0 )
            *a4 = 1;
        }
      }
      else
      {
LABEL_15:
        v27 = dp_tx_send(v21, *(_BYTE *)(a2 + 59), (__int64 *)a3);
        v28 = *(_QWORD *)v17;
        if ( v27 )
        {
          if ( v28 )
          {
            ++*(_QWORD *)(v28 + 3184);
            if ( *(_QWORD *)v17 )
              *(_QWORD *)(*(_QWORD *)v17 + 3192LL) += (unsigned __int16)v22;
          }
          ++*(_QWORD *)(v19 + 42976);
          _qdf_nbuf_free((__int64)v27);
        }
        else
        {
          if ( v28 )
          {
            ++*(_QWORD *)(v28 + 3168);
            if ( *(_QWORD *)v17 )
              *(_QWORD *)(*(_QWORD *)v17 + 3176LL) += (unsigned __int16)v22;
          }
          ++*(_QWORD *)(v19 + 42944);
          *a4 = 1;
        }
      }
    }
    else if ( a3 )
    {
      _qdf_nbuf_free(a3);
    }
    result = dp_peer_unref_delete(v17, 0xEu, v9, v10, v11, v12, v13, v14, v15, v16);
  }
  else if ( a3 )
  {
    result = _qdf_nbuf_free(a3);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
