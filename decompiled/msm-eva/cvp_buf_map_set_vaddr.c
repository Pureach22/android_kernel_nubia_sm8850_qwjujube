__int64 __fastcall cvp_buf_map_set_vaddr(__int64 result, __int64 a2)
{
  *(_QWORD *)result = a2;
  *(_BYTE *)(result + 8) = 0;
  return result;
}
