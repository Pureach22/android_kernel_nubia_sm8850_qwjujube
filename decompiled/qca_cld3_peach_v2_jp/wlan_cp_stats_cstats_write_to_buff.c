__int64 __fastcall wlan_cp_stats_cstats_write_to_buff(
        __int64 result,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w23
  const char *v12; // x2
  __int64 v13; // x21
  __int64 v14; // x8
  char *v15; // x26
  unsigned int v16; // w20
  unsigned int v17; // w19
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x22
  char *v28; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v30; // x9
  unsigned int *v31; // x25
  char v32; // w10
  unsigned int v33; // w8
  __int64 v34; // x19
  __int64 v35; // x10
  unsigned int v36; // w23
  __int64 v37; // x8
  unsigned int v38; // w8
  __int64 v39; // x8
  __int64 v40; // [xsp+0h] [xbp-10h] BYREF
  __int64 v41; // [xsp+8h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( byte_85CAD0 != 1 )
    goto LABEL_24;
  v11 = a3 + 36;
  v40 = 0;
  if ( a3 + 36 >= 0x801 )
  {
    v12 = "%s: The Buffer is too long";
LABEL_16:
    result = qdf_trace_msg(
               0x38u,
               2u,
               v12,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "wlan_cp_stats_cstats_write_to_buff",
               v40,
               v41);
LABEL_24:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( (unsigned int)result < 2 )
  {
    v13 = (unsigned int)result;
    v14 = 8LL * (unsigned int)result;
    if ( (v14 | 0x80uLL) <= 0xC0 )
    {
      v15 = (char *)&cstats + v14;
      if ( !*(_QWORD *)((char *)&cstats + v14 + 128) )
      {
        v12 = "%s: Current Node is NULL";
        goto LABEL_16;
      }
      v16 = result;
      v17 = a3;
      if ( byte_85CAD1 == 1 )
      {
        qdf_mem_copy(&v40, (const void *)(a2 + 8), 8u);
        qdf_trace_msg(
          0x62u,
          8u,
          "%s: CSTATS FW EVENT received at timestamp: %llu, event_len: %d",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "wlan_cp_stats_cstats_write_to_buff",
          v40,
          v17);
      }
      v27 = 16 * v13;
      v28 = (char *)&cstats + 16 * v13;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v28 + 96);
        goto LABEL_13;
      }
      result = raw_spin_lock_bh(v28 + 96);
      if ( (v27 | 0x68uLL) <= 0xC0 )
      {
        *((_QWORD *)v28 + 13) |= 1uLL;
LABEL_13:
        v30 = *((_QWORD *)v15 + 16);
        v31 = (unsigned int *)(v30 + 24);
        if ( 2048 - *(_DWORD *)(v30 + 24) >= v11 )
        {
          v32 = v16;
        }
        else
        {
          wlan_cp_stats_get_cstats_free_node(v16);
          v30 = *((_QWORD *)v15 + 16);
          v32 = v16;
          v31 = (unsigned int *)(v30 + 24);
        }
        v33 = v17;
        if ( (v32 & 1) != 0 )
        {
          v34 = v30 + 32;
          v35 = v30 + 32 + *v31;
          v36 = v33;
          *(_WORD *)(v35 + 4) = 19795;
          *(_DWORD *)v35 = 1180652355;
          result = (__int64)memcpy((void *)(v30 + 32 + *v31 + 6), (const void *)a2, v33);
          v37 = v34 + v36 + *v31 + 6;
          *(_DWORD *)v37 = 1180652355;
          *(_WORD *)(v37 + 4) = 19781;
          v38 = v36 + 12;
          v17 = *v31;
        }
        else
        {
          result = (__int64)memcpy((void *)(v30 + *v31 + 38), (const void *)a2, v17);
          v38 = *v31;
        }
        *v31 = v38 + v17;
        if ( (v27 | 0x68uLL) <= 0xC0 )
        {
          v39 = *((_QWORD *)v28 + 13);
          if ( (v39 & 1) != 0 )
          {
            *((_QWORD *)v28 + 13) = v39 & 0xFFFFFFFFFFFFFFFELL;
            result = raw_spin_unlock_bh(v28 + 96);
          }
          else
          {
            result = raw_spin_unlock(v28 + 96);
          }
          goto LABEL_24;
        }
      }
    }
    __break(1u);
  }
  __break(0x5512u);
  return wlan_cp_stats_get_cstats_free_node(result);
}
