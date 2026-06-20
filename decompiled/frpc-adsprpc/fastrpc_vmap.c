__int64 __fastcall fastrpc_vmap(__int64 a1, __int64 a2)
{
  __int64 v4; // x8

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 112) + 48LL);
  *(_BYTE *)(a2 + 8) = 0;
  *(_QWORD *)a2 = v4;
  return 0;
}
