__int64 __fastcall qdf_dp_trace_fill_meta_str(__int64 a1, unsigned int a2, unsigned int a3, char a4, __int64 *a5)
{
  __int64 v10; // x3
  const char *v11; // x7
  _QWORD *v12; // x6
  const char *v13; // x3
  __int64 result; // x0
  _QWORD v15[2]; // [xsp+0h] [xbp-20h] BYREF
  int v16; // [xsp+10h] [xbp-10h]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a5;
  v16 = 0;
  v15[0] = 0;
  v15[1] = 0;
  scnprintf(v15, 20, "%llu", v10);
  if ( (unsigned int)*((unsigned __int8 *)a5 + 8) - 1 > 0x29 )
    v11 = "Invalid";
  else
    v11 = off_AD04A8[(unsigned __int8)(*((_BYTE *)a5 + 8) - 1)];
  if ( (a4 & 1) != 0 )
    v12 = &unk_98C763;
  else
    v12 = v15;
  if ( (a4 & 2) != 0 )
    v13 = "*";
  else
    v13 = (const char *)&unk_98C763;
  result = scnprintf(a1, a2, "%s DPT: %04d:%02d%s %s", v13, a3, *((unsigned __int8 *)a5 + 80), v12, v11);
  _ReadStatusReg(SP_EL0);
  return result;
}
