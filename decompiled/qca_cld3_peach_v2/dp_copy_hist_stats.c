__int64 __fastcall dp_copy_hist_stats(__int64 result, __int64 a2)
{
  *(_QWORD *)(a2 + 8) = *(_QWORD *)(result + 8);
  *(_QWORD *)(a2 + 16) = *(_QWORD *)(result + 16);
  *(_QWORD *)(a2 + 24) = *(_QWORD *)(result + 24);
  *(_QWORD *)(a2 + 32) = *(_QWORD *)(result + 32);
  *(_QWORD *)(a2 + 40) = *(_QWORD *)(result + 40);
  *(_QWORD *)(a2 + 48) = *(_QWORD *)(result + 48);
  *(_QWORD *)(a2 + 56) = *(_QWORD *)(result + 56);
  *(_QWORD *)(a2 + 64) = *(_QWORD *)(result + 64);
  *(_QWORD *)(a2 + 72) = *(_QWORD *)(result + 72);
  *(_QWORD *)(a2 + 80) = *(_QWORD *)(result + 80);
  *(_QWORD *)(a2 + 88) = *(_QWORD *)(result + 88);
  *(_QWORD *)(a2 + 96) = *(_QWORD *)(result + 96);
  *(_QWORD *)(a2 + 104) = *(_QWORD *)(result + 104);
  *(_DWORD *)(a2 + 116) = *(_DWORD *)(result + 116);
  *(_DWORD *)(a2 + 112) = *(_DWORD *)(result + 112);
  *(_DWORD *)(a2 + 120) = *(_DWORD *)(result + 120);
  return result;
}
