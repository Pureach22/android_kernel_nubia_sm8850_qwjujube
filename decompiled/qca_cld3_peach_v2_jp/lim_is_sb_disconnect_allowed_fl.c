__int64 __fastcall lim_is_sb_disconnect_allowed_fl(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int v6; // w22
  unsigned int v7; // w23
  __int64 v8; // x0
  int v9; // w25
  __int64 v10; // x24
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v21; // [xsp+0h] [xbp-20h]
  int v22; // [xsp+10h] [xbp-10h]

  if ( *(_DWORD *)(a1 + 72) == 14 && (*(_DWORD *)(a1 + 80) & 0xFFFFFFFE) != 0xC )
    return 1;
  v6 = *(unsigned __int8 *)(a1 + 10);
  v7 = *(unsigned __int16 *)(a1 + 8);
  v8 = lim_mlm_state_str();
  v9 = *(_DWORD *)(a1 + 72);
  v10 = v8;
  v11 = lim_sme_state_str(*(unsigned int *)(a1 + 80));
  v22 = *(_DWORD *)(a1 + 80);
  v21 = v9;
  qdf_trace_msg(
    0x35u,
    4u,
    "%s:%u: Vdev %d (%d): limMlmState %s(%x) limSmeState %s(%x)",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    a2,
    a3,
    v6,
    v7,
    v10,
    v21,
    v11,
    v22);
  return 0;
}
