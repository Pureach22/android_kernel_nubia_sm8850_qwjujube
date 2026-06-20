__int64 __fastcall dp_rx_mon_link_desc_return(__int64 a1, unsigned int *a2, unsigned int a3)
{
  __int64 v3; // x9
  __int64 v5; // x20
  __int64 v6; // x19
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  unsigned int v16; // w9
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w22
  __int64 v26; // x10
  _QWORD *v27; // x23
  __int64 v28; // x8

  if ( a3 < 2 )
  {
    v3 = *(_QWORD *)(a1 + 8);
    v5 = *(_QWORD *)(v3 + 1128);
    v6 = *(_QWORD *)(v3 + 80LL * a3 + 160);
    if ( (unsigned int)hal_srng_access_start_2(v5, v6) )
    {
      qdf_trace_msg(
        0x3Fu,
        2u,
        "%s %d : \t\t\tHAL RING Access For WBM Release SRNG Failed -- %pK",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "dp_rx_mon_link_desc_return",
        134,
        v6);
    }
    else
    {
      v15 = *(unsigned int *)(v6 + 120);
      v16 = (unsigned int)(*(_DWORD *)(v6 + 44) + v15) % *(_DWORD *)(v6 + 36);
      if ( v16 != *(_DWORD *)(v6 + 136) )
      {
        v26 = *(_QWORD *)(v6 + 16);
        *(_DWORD *)(v6 + 120) = v16;
        *(_DWORD *)(v6 + 124) = v16;
        v27 = (_QWORD *)(v26 + 4 * v15);
        if ( v27 )
        {
          qdf_trace_msg(
            0x45u,
            8u,
            "[%s][%d] src_srng_desc=%pK, buf_addr=0x%llx, cookie=0x%llx",
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            "hal_rx_mon_msdu_link_desc_set",
            564,
            v27,
            *a2 | ((unsigned __int64)*((unsigned __int8 *)a2 + 4) << 32),
            *(_QWORD *)a2 >> 44);
          v25 = 0;
          *v27 = *(_QWORD *)a2;
LABEL_8:
          if ( !v6 )
          {
            qdf_trace_msg(
              0x38u,
              2u,
              "%s: Error: Invalid hal_ring\n",
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              "hal_srng_access_end");
            return v25;
          }
          if ( (*(_DWORD *)(v6 + 76) & 0x80000000) != 0 )
          {
            **(_DWORD **)(v6 + 144) = *(_DWORD *)(v6 + 120);
            v28 = *(_QWORD *)(v6 + 88);
            if ( (v28 & 1) == 0 )
              goto LABEL_11;
          }
          else
          {
            hal_delayed_reg_write(v5, (unsigned __int8 *)v6, *(_QWORD *)(v6 + 144), *(_DWORD *)(v6 + 120));
            v28 = *(_QWORD *)(v6 + 88);
            if ( (v28 & 1) == 0 )
            {
LABEL_11:
              raw_spin_unlock(v6 + 80);
              return v25;
            }
          }
          *(_QWORD *)(v6 + 88) = v28 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v6 + 80);
          return v25;
        }
      }
      qdf_trace_msg(
        0x3Fu,
        2u,
        "%s %d -- Monitor Link Desc WBM Release Ring Full",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "dp_rx_mon_link_desc_return",
        148);
    }
    v25 = 16;
    goto LABEL_8;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))hal_srng_access_start_2)();
}
