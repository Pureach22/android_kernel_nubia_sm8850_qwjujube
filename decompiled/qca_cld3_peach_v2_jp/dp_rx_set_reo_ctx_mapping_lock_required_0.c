double __fastcall dp_rx_set_reo_ctx_mapping_lock_required_0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double result,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x19
  unsigned __int64 v13; // x24
  char v14; // w25
  __int64 *v15; // x26
  __int64 v16; // x27
  unsigned __int64 StatusReg; // x28
  __int64 v18; // x20
  __int64 v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  if ( *(_BYTE *)(a1 + 12848) )
  {
    v12 = a1;
    v13 = 0;
    v14 = a2 & 1;
    v15 = (__int64 *)(a1 + 5712);
    v16 = a1 + 18480;
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( v13 != 8 )
    {
      v18 = *v15;
      if ( *v15 )
      {
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v18 + 80);
        }
        else
        {
          raw_spin_lock_bh(v18 + 80);
          *(_QWORD *)(v18 + 88) |= 1uLL;
        }
        *(_BYTE *)(v16 + v13) = v14;
        v19 = *(_QWORD *)(v18 + 88);
        if ( (v19 & 1) != 0 )
        {
          *(_QWORD *)(v18 + 88) = v19 & 0xFFFFFFFFFFFFFFFELL;
          a1 = raw_spin_unlock_bh(v18 + 80);
        }
        else
        {
          a1 = raw_spin_unlock(v18 + 80);
        }
      }
      else
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: error: invalid hal_ring\n",
          result,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "hal_srng_lock");
        *(_BYTE *)(v16 + v13) = v14;
        a1 = qdf_trace_msg(
               0x38u,
               2u,
               "%s: error: invalid hal_ring\n",
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               "hal_srng_unlock");
      }
      ++v13;
      v15 += 10;
      if ( v13 >= *(unsigned __int8 *)(v12 + 12848) )
        return result;
    }
    __break(0x5512u);
    return dp_ipa_intrabss_send(a1, a2, a3, a4);
  }
  return result;
}
