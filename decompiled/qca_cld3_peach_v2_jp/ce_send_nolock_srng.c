__int64 __fastcall ce_send_nolock_srng(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        unsigned __int16 a5,
        unsigned int a6)
{
  __int64 v6; // x27
  __int64 v7; // x19
  int v11; // w28
  __int64 v12; // x22
  _DWORD *v16; // x1
  unsigned int v17; // w8
  unsigned int v18; // w9
  bool v19; // cf
  unsigned int v20; // w8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w20
  __int64 v30; // x8
  __int64 v31; // x9
  __int64 v32; // x12
  __int64 v33; // x8
  __int64 v34; // x10
  unsigned __int64 v35; // x8
  char v36; // w9
  __int64 v37; // x24
  __int64 v38; // x23
  int v39; // w22
  __int64 v40; // x8

  v6 = *(_QWORD *)(a1 + 136);
  v7 = *(_QWORD *)a1;
  v11 = *(_DWORD *)(v6 + 4);
  v12 = *(unsigned int *)(v6 + 12);
  if ( (hif_target_sleep_state_adjust(*(_QWORD *)a1) & 0x80000000) != 0 )
  {
    return 16;
  }
  else
  {
    v16 = *(_DWORD **)(v6 + 80);
    v17 = v16[30];
    v18 = v16[34];
    v19 = v18 >= v17;
    v20 = v18 - v17;
    if ( v20 == 0 || !v19 )
      v20 += v16[9];
    if ( v20 / v16[11] == 1 )
    {
      v29 = 16;
      ++*(_DWORD *)(v7 + 596);
    }
    else if ( (unsigned int)hal_srng_access_start_1(*(_QWORD *)(v7 + 2560)) )
    {
      v29 = 16;
    }
    else
    {
      v30 = *(_QWORD *)(v6 + 80);
      v31 = *(unsigned int *)(v30 + 120);
      if ( (_DWORD)v31 == *(_DWORD *)(v30 + 124)
        || (v32 = *(_QWORD *)(v30 + 16) + 4 * v31,
            *(_DWORD *)(v30 + 120) = (unsigned int)(*(_DWORD *)(v30 + 44) + v31) % *(_DWORD *)(v30 + 36),
            !v32) )
      {
        v29 = 4;
      }
      else
      {
        v33 = *(_QWORD *)(v32 + 4);
        *(_DWORD *)v32 = a3;
        v34 = (a6 >> 5) & 0x800 | (a4 << 16);
        v35 = v33 & 0xFFFF0000FFFFFF00LL | BYTE4(a3) | ((unsigned __int64)a5 << 32);
        *(_QWORD *)(v32 + 4) = v35;
        v36 = (*(_DWORD *)(a1 + 12) >> 1) & ~(_BYTE)a6;
        v37 = v32;
        *(_QWORD *)(v32 + 4) = v35 & 0xFFFFFFFF0000F5FFLL | v34 | ((unsigned __int8)(v36 & 1) << 9);
        *(_QWORD *)(*(_QWORD *)(v6 + 88) + 8 * v12) = a2;
        v38 = *(_QWORD *)(v6 + 80);
        v39 = (v12 + 1) & v11;
        if ( v38 )
        {
          if ( (*(_DWORD *)(v38 + 76) & 0x80000000) != 0 )
            **(_DWORD **)(v38 + 144) = *(_DWORD *)(v38 + 120);
          else
            hal_delayed_reg_write(
              *(_QWORD *)(v7 + 2560),
              *(unsigned __int8 **)(v6 + 80),
              *(_QWORD *)(v38 + 144),
              *(_DWORD *)(v38 + 120));
          v40 = *(_QWORD *)(v38 + 88);
          if ( (v40 & 1) != 0 )
          {
            *(_QWORD *)(v38 + 88) = v40 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v38 + 80);
          }
          else
          {
            raw_spin_unlock(v38 + 80);
          }
        }
        else
        {
          qdf_trace_msg(
            0x38u,
            2u,
            "%s: Error: Invalid hal_ring\n",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "hal_srng_access_end");
        }
        ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64, _QWORD))hif_record_ce_srng_desc_event)(
          v7,
          *(unsigned int *)(a1 + 8),
          35,
          v37,
          a2,
          *(unsigned int *)(v6 + 12));
        v29 = 0;
        *(_DWORD *)(v6 + 12) = v39;
      }
    }
    hif_target_sleep_state_adjust(v7);
  }
  return v29;
}
