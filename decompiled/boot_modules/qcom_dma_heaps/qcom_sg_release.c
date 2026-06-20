__int64 __fastcall qcom_sg_release(__int64 a1)
{
  __int64 result; // x0
  __int64 (__fastcall *v3)(_QWORD); // x8

  result = mem_buf_vmperm_free(*(_QWORD *)(a1 - 48));
  v3 = *(__int64 (__fastcall **)(_QWORD))(a1 - 8);
  if ( v3 )
  {
    if ( *((_DWORD *)v3 - 1) != 1054465814 )
      __break(0x8228u);
    return v3(a1 - 168);
  }
  return result;
}
