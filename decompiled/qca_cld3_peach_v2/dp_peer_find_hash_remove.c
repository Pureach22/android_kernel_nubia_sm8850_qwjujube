__int64 __fastcall dp_peer_find_hash_remove(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v10; // w4
  __int64 v11; // x19
  int v12; // w23
  int v13; // w25
  unsigned int v15; // w24
  int v16; // w22
  int v17; // w21
  unsigned __int64 StatusReg; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x10
  _QWORD *v28; // x9
  __int64 (*v29)(void); // x8
  __int64 v30; // x8

  v10 = *(_DWORD *)(a2 + 408);
  v11 = result;
  if ( v10 == 2 )
  {
    v29 = *(__int64 (**)(void))(result + 1528);
    if ( v29 )
    {
      if ( *((_DWORD *)v29 - 1) != -1773781185 )
        __break(0x8228u);
      return v29();
    }
  }
  else if ( v10 == 1 )
  {
    v12 = *(unsigned __int16 *)(a2 + 46);
    v13 = *(unsigned __int16 *)(a2 + 44);
    v15 = *(unsigned __int16 *)(a2 + 48);
    v16 = *(_DWORD *)(result + 13148);
    v17 = *(_DWORD *)(result + 13144);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 13288);
    }
    else
    {
      raw_spin_lock_bh(result + 13288);
      *(_QWORD *)(v11 + 13296) |= 1uLL;
    }
    v27 = *(_QWORD *)(a2 + 72);
    v28 = *(_QWORD **)(a2 + 80);
    if ( v27 )
      *(_QWORD *)(v27 + 80) = v28;
    else
      *(_QWORD *)(*(_QWORD *)(v11 + 13152) + 16LL * ((((v13 ^ v12 ^ v15) >> v16) ^ v13 ^ v12 ^ v15) & v17) + 8) = v28;
    *v28 = *(_QWORD *)(a2 + 72);
    *(_QWORD *)(a2 + 72) = 0;
    *(_QWORD *)(a2 + 80) = 0;
    dp_peer_unref_delete(a2, 0xCu, v19, v20, v21, v22, v23, v24, v25, v26);
    v30 = *(_QWORD *)(v11 + 13296);
    if ( (v30 & 1) != 0 )
    {
      *(_QWORD *)(v11 + 13296) = v30 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v11 + 13288);
    }
    else
    {
      return raw_spin_unlock(v11 + 13288);
    }
  }
  else
  {
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: unknown peer type %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "dp_peer_find_hash_remove");
  }
  return result;
}
