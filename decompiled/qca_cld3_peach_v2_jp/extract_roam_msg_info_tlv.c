__int64 __fastcall extract_roam_msg_info_tlv(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4)
{
  __int64 v4; // x8
  _DWORD *v5; // x8

  if ( a2 )
  {
    v4 = *(_QWORD *)(a2 + 176);
    if ( v4 )
    {
      if ( *(_DWORD *)(a2 + 184) > (unsigned int)a4 )
      {
        v5 = (_DWORD *)(v4 + 20LL * a4);
        *(_BYTE *)a3 = 1;
        *(_DWORD *)(a3 + 4) = v5[1];
        *(_DWORD *)(a3 + 8) = v5[2];
        *(_DWORD *)(a3 + 12) = v5[3];
        *(_DWORD *)(a3 + 16) = v5[4];
      }
    }
  }
  return 0;
}
