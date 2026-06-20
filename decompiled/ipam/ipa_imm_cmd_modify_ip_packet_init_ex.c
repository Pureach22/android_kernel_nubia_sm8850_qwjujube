__int64 __fastcall ipa_imm_cmd_modify_ip_packet_init_ex(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( *(_BYTE *)a4 == 1 )
    *(_DWORD *)a2 = *(_DWORD *)a2 & 0xFFFEFFFF | ((*(_BYTE *)a3 & 1) << 16);
  if ( *(_BYTE *)(a4 + 1) == 1 )
    *(_DWORD *)a2 = *(_DWORD *)a2 & 0xFFFDFFFF | ((*(_BYTE *)(a3 + 1) & 1) << 17);
  if ( *(_BYTE *)(a4 + 2) == 1 )
    *(_DWORD *)a2 = *(_DWORD *)a2 & 0xFFFBFFFF | ((*(_BYTE *)(a3 + 2) & 1) << 18);
  if ( *(_BYTE *)(a4 + 3) == 1 )
    *(_DWORD *)a2 = *(_DWORD *)a2 & 0xFFF7FFFF | ((*(_BYTE *)(a3 + 3) & 1) << 19);
  if ( *(_BYTE *)(a4 + 4) == 1 )
    *(_DWORD *)a2 = *(_DWORD *)a2 & 0xFFEFFFFF | ((*(_BYTE *)(a3 + 4) & 1) << 20);
  if ( *(_BYTE *)(a4 + 5) == 1 )
    *(_DWORD *)a2 = *(_DWORD *)a2 & 0xFFDFFFFF | ((*(_BYTE *)(a3 + 5) & 1) << 21);
  if ( *(_BYTE *)(a4 + 6) == 1 )
    *(_DWORD *)a2 = *(_DWORD *)a2 & 0xFFBFFFFF | ((*(_BYTE *)(a3 + 6) & 1) << 22);
  if ( *(_BYTE *)(a4 + 7) )
    *(_BYTE *)(a2 + 4) = *(_BYTE *)(a3 + 7);
  if ( *(_BYTE *)(a4 + 8) )
    *(_BYTE *)(a2 + 5) = *(_BYTE *)(a3 + 8);
  if ( *(_BYTE *)(a4 + 9) )
    *(_BYTE *)(a2 + 6) = *(_BYTE *)(a3 + 9);
  if ( *(_BYTE *)(a4 + 10) == 1 )
    *(_QWORD *)(a2 + 4) = *(_QWORD *)(a2 + 4) & 0xFFFFFFFFFDFFFFFFLL
                        | ((unsigned __int64)(*(_BYTE *)(a3 + 10) & 1) << 25);
  if ( *(_BYTE *)(a4 + 11) )
    *(_QWORD *)(a2 + 4) = *(_QWORD *)(a2 + 4) & 0xFFFFFE0FFFFFFFFFLL
                        | ((unsigned __int64)(*(_BYTE *)(a3 + 11) & 0x1F) << 36);
  if ( *(_BYTE *)(a4 + 12) )
    *(_QWORD *)(a2 + 4) = *(_QWORD *)(a2 + 4) & 0xFFFFE1FFFFFFFFFFLL
                        | ((unsigned __int64)(*(_BYTE *)(a3 + 12) & 0xF) << 41);
  if ( *(_BYTE *)(a4 + 13) == 1 )
    *(_QWORD *)(a2 + 4) = *(_QWORD *)(a2 + 4) & 0xFFFFDFFFFFFFFFFFLL
                        | ((unsigned __int64)(*(_BYTE *)(a3 + 13) & 1) << 45);
  if ( *(_BYTE *)(a4 + 14) == 1 )
    *(_QWORD *)(a2 + 4) = *(_QWORD *)(a2 + 4) & 0xFFFFBFFFFFFFFFFFLL
                        | ((unsigned __int64)(*(_BYTE *)(a3 + 14) & 1) << 46);
  if ( *(_BYTE *)(a4 + 15) )
    *(_BYTE *)(a2 + 10) = *(_BYTE *)(a3 + 15);
  if ( *(_BYTE *)(a4 + 16) )
    *(_BYTE *)(a2 + 11) = *(_BYTE *)(a3 + 16);
  if ( *(_BYTE *)(a4 + 17) )
    *(_BYTE *)(a2 + 12) = *(_BYTE *)(a3 + 17);
  if ( *(_BYTE *)(a4 + 18) == 1 )
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(a2 + 12) & 0xFFFFFDFF | ((*(_BYTE *)(a3 + 18) & 1) << 9);
  if ( *(_WORD *)(a4 + 20) )
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(a2 + 12) & 0xE00FFFFF | ((*(_WORD *)(a3 + 20) & 0x1FF) << 20);
  if ( *(_BYTE *)(a4 + 22) == 1 )
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(a2 + 12) & 0xDFFFFFFF | ((*(_BYTE *)(a3 + 22) & 1) << 29);
  if ( *(_BYTE *)(a4 + 23) == 1 )
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(a2 + 12) & 0xBFFFFFFF | ((*(_BYTE *)(a3 + 23) & 1) << 30);
  if ( *(_BYTE *)(a4 + 24) == 1 )
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(a2 + 12) & 0x7FFFFFFF | (*(unsigned __int8 *)(a3 + 24) << 31);
  return 0;
}
