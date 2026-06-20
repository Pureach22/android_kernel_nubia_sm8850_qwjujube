__int64 __fastcall dp_set_pdev_pcp_tid_map_wifi3(__int64 a1, __int64 a2, unsigned int a3, char a4)
{
  __int64 v4; // x8
  __int64 v5; // x0
  _DWORD *v6; // x8

  if ( (unsigned __int8)a3 >= 8u )
  {
    __break(0x5512u);
    return dp_set_vdev_pcp_tid_map_wifi3();
  }
  else
  {
    v4 = a1 + (unsigned __int8)a3;
    v5 = *(_QWORD *)(a1 + 1128);
    *(_BYTE *)(v4 + 18729) = a4;
    v6 = *(_DWORD **)(*(_QWORD *)(v5 + 74392) + 472LL);
    if ( *(v6 - 1) != -150753328 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v6)(v5, a3);
    return 0;
  }
}
