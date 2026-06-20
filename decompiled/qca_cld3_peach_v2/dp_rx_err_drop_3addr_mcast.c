bool __fastcall dp_rx_err_drop_3addr_mcast(__int64 a1, __int64 a2)
{
  unsigned __int8 (__fastcall *v2)(_QWORD); // x8

  if ( *(_BYTE *)(a1 + 50) != 1 || *(_DWORD *)(a1 + 32) != 3 )
    return 0;
  v2 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 8LL)
                                                                        + 1128LL)
                                                            + 74392LL)
                                                + 496LL);
  if ( *((_DWORD *)v2 - 1) != -1147376687 )
    __break(0x8228u);
  return v2(a2) != 0;
}
