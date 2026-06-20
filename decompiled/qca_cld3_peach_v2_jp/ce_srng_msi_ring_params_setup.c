__int64 __fastcall ce_srng_msi_ring_params_setup(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x0
  unsigned int v10; // w21
  unsigned __int64 v11; // x6
  int v12; // w8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v23; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v24; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 576);
  v24 = 0;
  v23 = 0;
  v7 = *(_QWORD *)(v6 + 40);
  v22 = 0;
  v21 = 0;
  result = pld_get_user_msi_assignment(v7, (__int64)"CE", (__int64)&v22, (__int64)&v22 + 4, (__int64)&v21);
  if ( (_DWORD)result )
    goto LABEL_4;
  if ( a2 < 0xC )
  {
    v9 = *(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL);
    v10 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 664) + a2);
    pld_get_msi_address(v9, (__int64)&v24, (__int64)&v23);
    v11 = v24 | ((unsigned __int64)v23 << 32);
    v12 = *(_DWORD *)(a3 + 48) | 0x20000;
    *(_DWORD *)(a3 + 32) = HIDWORD(v22) + v10;
    *(_QWORD *)(a3 + 24) = v11;
    *(_DWORD *)(a3 + 48) = v12;
    result = qdf_trace_msg(
               0x3Du,
               8u,
               "%s: ce_id %d irq_id %d, msi_addr %pK, msi_data %d",
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "ce_srng_msi_ring_params_setup",
               a2,
               v10);
LABEL_4:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return hal_srng_access_start_1(result);
}
