__int64 __fastcall ipa_imm_cmd_modify_ip_packet_init_ex_v5_5(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( *(_BYTE *)a4 == 1 )
    *(_QWORD *)a2 = *(_QWORD *)a2 & 0xFFFFFFFFFFFEFFFFLL | ((unsigned __int64)(*(_BYTE *)a3 & 1) << 16);
  if ( *(_BYTE *)(a4 + 1) == 1 )
    *(_QWORD *)a2 = *(_QWORD *)a2 & 0xFFFFFFFFFFFDFFFFLL | ((unsigned __int64)(*(_BYTE *)(a3 + 1) & 1) << 17);
  if ( *(_BYTE *)(a4 + 2) == 1 )
    *(_QWORD *)a2 = *(_QWORD *)a2 & 0xFFFFFFFFFFFBFFFFLL | ((unsigned __int64)(*(_BYTE *)(a3 + 2) & 1) << 18);
  if ( *(_BYTE *)(a4 + 3) == 1 )
    *(_QWORD *)a2 = *(_QWORD *)a2 & 0xFFFFFFFFFFF7FFFFLL | ((unsigned __int64)(*(_BYTE *)(a3 + 3) & 1) << 19);
  if ( *(_BYTE *)(a4 + 4) == 1 )
    *(_QWORD *)a2 = *(_QWORD *)a2 & 0xFFFFFFFFFFEFFFFFLL | ((unsigned __int64)(*(_BYTE *)(a3 + 4) & 1) << 20);
  if ( *(_BYTE *)(a4 + 5) == 1 )
    *(_QWORD *)a2 = *(_QWORD *)a2 & 0xFFFFFFFFFFDFFFFFLL | ((unsigned __int64)(*(_BYTE *)(a3 + 5) & 1) << 21);
  if ( *(_BYTE *)(a4 + 6) == 1 )
    *(_QWORD *)a2 = *(_QWORD *)a2 & 0xFFFFFFFFFFBFFFFFLL | ((unsigned __int64)(*(_BYTE *)(a3 + 6) & 1) << 22);
  if ( *(_BYTE *)(a4 + 25) == 1 )
    *(_QWORD *)a2 = *(_QWORD *)a2 & 0xFFFFFFFFFF7FFFFFLL | ((unsigned __int64)(*(_BYTE *)(a3 + 25) & 1) << 23);
  if ( *(_BYTE *)(a4 + 7) )
    *(_BYTE *)(a2 + 8) = *(_BYTE *)(a3 + 7);
  if ( *(_BYTE *)(a4 + 8) )
    *(_BYTE *)(a2 + 9) = *(_BYTE *)(a3 + 8);
  if ( *(_BYTE *)(a4 + 9) )
    *(_BYTE *)(a2 + 10) = *(_BYTE *)(a3 + 9);
  if ( *(_BYTE *)(a4 + 10) == 1 )
    *(_QWORD *)(a2 + 8) = *(_QWORD *)(a2 + 8) & 0xFFFFFFFFFDFFFFFFLL
                        | ((unsigned __int64)(*(_BYTE *)(a3 + 10) & 1) << 25);
  if ( *(_BYTE *)(a4 + 11) )
    *(_QWORD *)(a2 + 8) = *(_QWORD *)(a2 + 8) & 0xFFFFFE0FFFFFFFFFLL
                        | ((unsigned __int64)(*(_BYTE *)(a3 + 11) & 0x1F) << 36);
  if ( *(_BYTE *)(a4 + 12) )
    *(_QWORD *)(a2 + 8) = *(_QWORD *)(a2 + 8) & 0xFFFFE1FFFFFFFFFFLL
                        | ((unsigned __int64)(*(_BYTE *)(a3 + 12) & 0xF) << 41);
  if ( *(_BYTE *)(a4 + 13) == 1 )
    *(_QWORD *)(a2 + 8) = *(_QWORD *)(a2 + 8) & 0xFFFFDFFFFFFFFFFFLL
                        | ((unsigned __int64)(*(_BYTE *)(a3 + 13) & 1) << 45);
  if ( *(_BYTE *)(a4 + 14) == 1 )
    *(_QWORD *)(a2 + 8) = *(_QWORD *)(a2 + 8) & 0xFFFFBFFFFFFFFFFFLL
                        | ((unsigned __int64)(*(_BYTE *)(a3 + 14) & 1) << 46);
  if ( *(_BYTE *)(a4 + 15) )
    *(_BYTE *)(a2 + 16) = *(_BYTE *)(a3 + 15);
  if ( *(_BYTE *)(a4 + 16) )
    *(_BYTE *)(a2 + 17) = *(_BYTE *)(a3 + 16);
  if ( *(_BYTE *)(a4 + 17) )
    *(_BYTE *)(a2 + 18) = *(_BYTE *)(a3 + 17);
  if ( *(_BYTE *)(a4 + 18) == 1 )
    *(_QWORD *)(a2 + 16) = *(_QWORD *)(a2 + 16) & 0xFFFFFFFFFDFFFFFFLL
                         | ((unsigned __int64)(*(_BYTE *)(a3 + 18) & 1) << 25);
  if ( *(_WORD *)(a4 + 20) )
    *(_QWORD *)(a2 + 16) = *(_QWORD *)(a2 + 16) & 0xFFFFE00FFFFFFFFFLL
                         | ((unsigned __int64)(*(_WORD *)(a3 + 20) & 0x1FF) << 36);
  if ( *(_BYTE *)(a4 + 22) == 1 )
    *(_QWORD *)(a2 + 16) = *(_QWORD *)(a2 + 16) & 0xFFFFDFFFFFFFFFFFLL
                         | ((unsigned __int64)(*(_BYTE *)(a3 + 22) & 1) << 45);
  if ( *(_BYTE *)(a4 + 23) == 1 )
    *(_QWORD *)(a2 + 16) = *(_QWORD *)(a2 + 16) & 0xFFFFBFFFFFFFFFFFLL
                         | ((unsigned __int64)(*(_BYTE *)(a3 + 23) & 1) << 46);
  if ( *(_BYTE *)(a4 + 24) == 1 )
    *(_QWORD *)(a2 + 16) = *(_QWORD *)(a2 + 16) & 0xFFFF7FFFFFFFFFFFLL
                         | ((unsigned __int64)(*(_BYTE *)(a3 + 24) & 1) << 47);
  if ( *(_BYTE *)(a4 + 26) == 1 )
    *(_QWORD *)(a2 + 8) = *(_QWORD *)(a2 + 8) & 0xFFFFFFFFFEFFFFFFLL
                        | ((unsigned __int64)(*(_BYTE *)(a3 + 26) & 1) << 24);
  if ( *(_BYTE *)(a4 + 27) == 1 )
    *(_QWORD *)(a2 + 8) = *(_QWORD *)(a2 + 8) & 0xFFFEFFFFFFFFFFFFLL
                        | ((unsigned __int64)(*(_BYTE *)(a3 + 27) & 1) << 48);
  if ( *(_BYTE *)(a4 + 28) )
    *(_QWORD *)(a2 + 8) = *(_QWORD *)(a2 + 8) & 0xFF81FFFFFFFFFFFFLL
                        | ((unsigned __int64)(*(_BYTE *)(a3 + 28) & 0x3F) << 49);
  if ( *(_BYTE *)(a4 + 29) == 1 )
    *(_QWORD *)(a2 + 16) = *(_QWORD *)(a2 + 16) & 0xFFFFFFFFFEFFFFFFLL
                         | ((unsigned __int64)(*(_BYTE *)(a3 + 29) & 1) << 24);
  if ( *(_BYTE *)(a4 + 30) == 1 )
    *(_QWORD *)(a2 + 16) = *(_QWORD *)(a2 + 16) & 0xFFFEFFFFFFFFFFFFLL
                         | ((unsigned __int64)(*(_BYTE *)(a3 + 30) & 1) << 48);
  if ( *(_BYTE *)(a4 + 31) )
    *(_QWORD *)(a2 + 16) = *(_QWORD *)(a2 + 16) & 0xFF81FFFFFFFFFFFFLL
                         | ((unsigned __int64)(*(_BYTE *)(a3 + 31) & 0x3F) << 49);
  if ( *(_BYTE *)(a4 + 32) == 1 )
    *(_QWORD *)(a2 + 16) = *(_QWORD *)(a2 + 16) & 0xFF7FFFFFFFFFFFFFLL
                         | ((unsigned __int64)(*(_BYTE *)(a3 + 32) & 1) << 55);
  return 0;
}
