__int64 __fastcall hal_rx_msdu_reo_dst_ind_get_be(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v3)(_QWORD); // x8
  __int64 v4; // x0
  __int64 (__fastcall *v5)(_QWORD); // x8

  v3 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 74392) + 424LL);
  if ( *((_DWORD *)v3 - 1) != -1437795666 )
    __break(0x8228u);
  v4 = v3(a2);
  v5 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 74392) + 1184LL);
  if ( *((_DWORD *)v5 - 1) != -1437795666 )
    __break(0x8228u);
  return *(_DWORD *)v5(v4) & 0x1F;
}
