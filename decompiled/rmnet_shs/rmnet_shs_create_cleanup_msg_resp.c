__int64 __fastcall rmnet_shs_create_cleanup_msg_resp(__int64 result)
{
  if ( result )
  {
    *(_QWORD *)(result + 88) = 0;
    *(_QWORD *)(result + 96) = 0;
    *(_WORD *)(result + 98) = 4;
    *(_QWORD *)(result + 104) = 0;
    *(_QWORD *)(result + 112) = 0;
    *(_QWORD *)(result + 72) = 0;
    *(_QWORD *)(result + 80) = 0;
    *(_QWORD *)(result + 56) = 0;
    *(_QWORD *)(result + 64) = 0;
    *(_QWORD *)(result + 40) = 0;
    *(_QWORD *)(result + 48) = 0;
    *(_QWORD *)(result + 24) = 0;
    *(_QWORD *)(result + 32) = 0;
    *(_QWORD *)(result + 8) = 0;
    *(_QWORD *)(result + 16) = 0;
    *(_QWORD *)result = 0;
    *(_BYTE *)(result + 114) = 1;
    *(_WORD *)(result + 112) = 1;
  }
  return result;
}
