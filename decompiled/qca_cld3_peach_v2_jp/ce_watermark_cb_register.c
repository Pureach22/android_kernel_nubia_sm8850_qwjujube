__int64 __fastcall ce_watermark_cb_register(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 (*v6)(void); // x8
  __int64 result; // x0

  v3 = *a1;
  a1[14] = a2;
  a1[15] = a3;
  v6 = *(__int64 (**)(void))(*(_QWORD *)(v3 + 30696) + 104LL);
  if ( *((_DWORD *)v6 - 1) != -1108450135 )
    __break(0x8228u);
  result = v6();
  if ( a2 )
    *((_BYTE *)a1 + 104) = 1;
  return result;
}
