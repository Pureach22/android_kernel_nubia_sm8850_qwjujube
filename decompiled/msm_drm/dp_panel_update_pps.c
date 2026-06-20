__int64 __fastcall dp_panel_update_pps(__int64 a1)
{
  __int64 v1; // x8
  __int64 (__fastcall *v2)(_QWORD); // x10

  v1 = *(_QWORD *)(a1 + 1216);
  v2 = *(__int64 (__fastcall **)(_QWORD))(v1 + 688);
  *(_DWORD *)(v1 + 204) = *(_DWORD *)(a1 + 912);
  if ( *((_DWORD *)v2 - 1) != 440525842 )
    __break(0x822Au);
  return v2(v1);
}
