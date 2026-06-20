int *__fastcall user_input_param_override(int *result)
{
  __int64 v1; // x21
  int v2; // w20
  __int64 *v3; // x22
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  void (__fastcall *v7)(__int64, __int64, __int64); // x8

  if ( result && *((_QWORD *)result + 1) && *(_QWORD *)result && (result[20] & 1) == 0 && result[26] > 0 )
  {
    v1 = *((_QWORD *)result + 12);
    v2 = 0;
    do
    {
      v3 = (__int64 *)result;
      dev_info(
        *((_QWORD *)result + 2),
        "write 0x%02x to 0x%02x\n",
        *(unsigned __int8 *)(v1 + v2),
        *(unsigned __int8 *)(v1 + v2 + 1));
      v4 = *v3;
      v5 = *(unsigned __int8 *)(v1 + v2);
      v6 = *(unsigned __int8 *)(v1 + v2 + 1);
      v7 = *(void (__fastcall **)(__int64, __int64, __int64))(v3[1] + 8);
      if ( *((_DWORD *)v7 - 1) != 602064488 )
        __break(0x8228u);
      v7(v4, v5, v6);
      v2 += 2;
      result = (int *)v3;
    }
    while ( v2 < *((_DWORD *)v3 + 26) );
  }
  return result;
}
