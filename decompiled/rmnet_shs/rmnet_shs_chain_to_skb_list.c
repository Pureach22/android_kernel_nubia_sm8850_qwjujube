__int64 __fastcall rmnet_shs_chain_to_skb_list(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v7; // x19
  __int64 v9; // x8
  __int64 v10; // x9
  unsigned __int64 v11; // x8
  int v12; // w8
  unsigned __int64 v13; // x8
  __int64 v14; // x9
  __int64 v15; // x10
  __int64 v16; // x11
  __int64 v17; // x8
  __int64 v18; // x9
  int v19; // w9
  int v20; // w8
  unsigned __int64 StatusReg; // x21
  __int64 v22; // x8

  v7 = result;
  v9 = *(_QWORD *)(result + 216) + *(unsigned int *)(result + 212);
  v10 = *(unsigned __int16 *)(v9 + 6);
  if ( !*(_WORD *)(v9 + 6) )
  {
    v13 = *(unsigned __int16 *)(a2 + 210);
    ++*(_QWORD *)(a2 + 144);
    if ( v13 <= 7 )
    {
      ++HIDWORD(rmnet_shs_cpu_node_tbl[5 * (unsigned int)v13 + 3]);
      v12 = 1;
      goto LABEL_6;
    }
LABEL_14:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      result = _traceiter_rmnet_shs_high(0, 7, 32, a4, a5, a6, a7, result);
      v22 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v22;
      if ( !v22 || !*(_QWORD *)(StatusReg + 16) )
        return preempt_schedule_notrace(result);
    }
    return result;
  }
  v11 = *(unsigned __int16 *)(a2 + 210);
  *(_QWORD *)(a2 + 144) += v10;
  if ( v11 >= 8 )
    goto LABEL_14;
  ++HIDWORD(rmnet_shs_cpu_node_tbl[5 * (unsigned int)v11 + 3]);
  v12 = *(unsigned __int16 *)(*(_QWORD *)(result + 216) + *(unsigned int *)(result + 212) + 6LL);
LABEL_6:
  v15 = *(_QWORD *)(a2 + 152);
  v14 = *(_QWORD *)(a2 + 160);
  *(_DWORD *)(a2 + 124) += v12;
  *(_QWORD *)(a2 + 152) = v15 + 1;
  v16 = *(_QWORD *)(a2 + 176);
  *(_QWORD *)(a2 + 168) += *(unsigned int *)(result + 44);
  *(_QWORD *)(a2 + 176) = v16 + *(unsigned int *)(result + 48);
  *(_DWORD *)(a2 + 196) = *(_DWORD *)(result + 52);
  *(_DWORD *)(a2 + 200) = *(_DWORD *)(result + 56);
  v17 = v14 + *(unsigned int *)(result + 112);
  v18 = *(_QWORD *)(a2 + 112);
  *(_QWORD *)(a2 + 160) = v17;
  *(_QWORD *)(a2 + 112) = v18 + *(unsigned int *)(result + 112);
  qword_19460 += *(unsigned int *)(result + 112);
  if ( *(_DWORD *)(a2 + 120) )
  {
    **(_QWORD **)(a2 + 104) = result;
    v19 = *(_DWORD *)(a2 + 120);
    *(_QWORD *)(a2 + 104) = **(_QWORD **)(a2 + 104);
    v20 = v19 + 1;
  }
  else
  {
    v20 = 1;
    *(_QWORD *)(a2 + 96) = result;
    *(_QWORD *)(a2 + 104) = result;
  }
  *(_DWORD *)(a2 + 120) = v20;
  ++qword_19468;
  if ( *(_BYTE *)(a2 + 225) )
  {
    if ( *(_BYTE *)(a2 + 226) )
      return result;
LABEL_13:
    result = rmnet_shs_is_skb_ecn_capable(v7, a2, a3, a4, a5);
    *(_BYTE *)(a2 + 226) = result;
    return result;
  }
  result = rmnet_shs_is_skb_l4s(result, a2, a3, a4, a5);
  *(_BYTE *)(a2 + 225) = result;
  if ( !*(_BYTE *)(a2 + 226) )
    goto LABEL_13;
  return result;
}
