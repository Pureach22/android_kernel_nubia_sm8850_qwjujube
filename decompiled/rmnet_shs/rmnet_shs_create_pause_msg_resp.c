void __fastcall rmnet_shs_create_pause_msg_resp(__int64 a1, __int64 a2)
{
  if ( a2 )
  {
    *(_QWORD *)(a2 + 88) = 0;
    *(_QWORD *)(a2 + 96) = 0;
    *(_WORD *)(a2 + 98) = 3;
    *(_QWORD *)(a2 + 104) = 0;
    *(_QWORD *)(a2 + 112) = 0;
    *(_QWORD *)(a2 + 72) = 0;
    *(_QWORD *)(a2 + 80) = 0;
    *(_QWORD *)(a2 + 56) = 0;
    *(_QWORD *)(a2 + 64) = 0;
    *(_QWORD *)(a2 + 40) = 0;
    *(_QWORD *)(a2 + 48) = 0;
    *(_QWORD *)(a2 + 24) = 0;
    *(_QWORD *)(a2 + 32) = 0;
    *(_QWORD *)(a2 + 8) = 0;
    *(_QWORD *)(a2 + 16) = 0;
    *(_QWORD *)a2 = 0;
    *(_BYTE *)(a2 + 114) = 1;
    *(_WORD *)(a2 + 112) = 1;
  }
}
