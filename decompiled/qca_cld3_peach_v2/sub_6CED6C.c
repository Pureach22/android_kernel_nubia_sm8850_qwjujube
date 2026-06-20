__int64 __fastcall sub_6CED6C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 v11; // x6

  _T1 = *(_QWORD *)(a7 + 132);
  v11 = a7 + 132;
  __asm { STGP            X7, X13, [X6,#0x84]! }
  return send_mlo_link_recfg_complete_cmd_tlv(a1, a2, a3, a4, a5, a6, v11, _X7);
}
