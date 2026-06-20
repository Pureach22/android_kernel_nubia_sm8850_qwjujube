__int64 __fastcall fastrpc_release(__int64 a1)
{
  return fastrpc_buf_free(*(_QWORD *)(a1 + 112), 0);
}
