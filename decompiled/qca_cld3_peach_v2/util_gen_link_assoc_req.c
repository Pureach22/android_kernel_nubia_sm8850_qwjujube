__int64 __fastcall util_gen_link_assoc_req(int a1, int a2, char a3, int a4, int a5, int a6, int a7, __int64 a8)
{
  int v8; // w2

  if ( (a3 & 1) != 0 )
    v8 = 2;
  else
    v8 = 0;
  return util_gen_link_reqrsp_cmn(a1, a2, v8, a4, a5, 0, a6, a7, a8);
}
