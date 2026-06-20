__int64 __fastcall qmi_rmnet_qos_init(__int64 a1, __int64 a2, char a3)
{
  __int64 result; // x0

  result = _kmalloc_cache_noprof(memset, 3520, 344);
  if ( result )
  {
    *(_BYTE *)(result + 16) = a3;
    *(_QWORD *)(result + 24) = a1;
    *(_QWORD *)(result + 32) = a2;
    *(_QWORD *)(result + 328) = 0;
    *(_QWORD *)(result + 40) = result + 40;
    *(_QWORD *)(result + 48) = result + 40;
    *(_QWORD *)(result + 56) = result + 56;
    *(_QWORD *)(result + 64) = result + 56;
  }
  return result;
}
