__int64 __fastcall qcom_sg_vunmap(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  int v4; // w8
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 112);
  mutex_lock(v2 + 24);
  v4 = *(_DWORD *)(v2 + 96) - 1;
  *(_DWORD *)(v2 + 96) = v4;
  if ( !v4 )
  {
    vunmap(*(_QWORD *)(v2 + 104));
    *(_QWORD *)(v2 + 104) = 0;
  }
  mem_buf_vmperm_unpin(*(_QWORD *)(v2 + 120));
  result = mutex_unlock(v2 + 24);
  if ( *(_BYTE *)(a2 + 8) == 1 )
    *(_BYTE *)(a2 + 8) = 0;
  *(_QWORD *)a2 = 0;
  return result;
}
