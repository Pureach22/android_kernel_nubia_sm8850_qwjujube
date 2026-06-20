__int64 __fastcall rndis_add_hdr(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    result = skb_push(result, 44);
    *(_QWORD *)(result + 4) = 0;
    *(_QWORD *)(result + 12) = 0;
    *(_QWORD *)(result + 20) = 0;
    *(_QWORD *)(result + 28) = 0;
    *(_QWORD *)(result + 36) = 0;
    *(_DWORD *)result = 1;
    *(_DWORD *)(result + 4) = *(_DWORD *)(v1 + 112);
    *(_DWORD *)(result + 8) = 36;
    *(_DWORD *)(result + 12) = *(_DWORD *)(v1 + 112) - 44;
  }
  return result;
}
