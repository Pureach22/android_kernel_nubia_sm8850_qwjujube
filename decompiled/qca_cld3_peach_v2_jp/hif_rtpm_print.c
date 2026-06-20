__int64 __fastcall hif_rtpm_print(
        __int64 result,
        int *a2,
        __int64 a3,
        const char *a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        char a9)
{
  __int64 v10; // x9
  char *v11; // [xsp+28h] [xbp-48h] BYREF
  char **v12; // [xsp+30h] [xbp-40h]
  __int64 v13; // [xsp+38h] [xbp-38h]
  __int64 v14; // [xsp+40h] [xbp-30h]
  char *v15; // [xsp+48h] [xbp-28h]
  char **v16; // [xsp+50h] [xbp-20h]
  __int64 v17; // [xsp+58h] [xbp-18h]
  __int64 v18; // [xsp+60h] [xbp-10h]
  __int64 v19; // [xsp+68h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = &a9;
  v16 = &v11;
  v17 = 0;
  v18 = 4294967264LL;
  if ( (_DWORD)result == 1 )
  {
    v11 = v15;
    v12 = v16;
    v13 = v17;
    v14 = v18;
    result = seq_vprintf(a3, a4, &v11);
  }
  else if ( !(_DWORD)result && a2 )
  {
    v11 = v15;
    v12 = v16;
    v10 = *a2;
    v13 = v17;
    v14 = v18;
    result = vscnprintf(a3 + v10, 4096, a4, &v11);
    *a2 += result;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
