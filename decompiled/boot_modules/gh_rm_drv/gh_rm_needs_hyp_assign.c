__int64 __fastcall gh_rm_needs_hyp_assign(int *a1, int a2, int *a3, int a4)
{
  __int64 result; // x0
  __int64 v9; // x13
  int *v10; // x15
  unsigned int v11; // w16
  int v12; // t1
  __int64 v13; // x13
  int *v14; // x15
  unsigned int v15; // w16
  int v16; // t1
  __int16 v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (gh_feature_use_scm_assign & 1) == 0 )
  {
    v17 = 0;
    if ( !(unsigned int)gh_rm_get_this_vmid(&v17) )
    {
      if ( v17 != 3 )
        goto LABEL_24;
      if ( a2 >= 1 )
      {
        v9 = (unsigned int)a2;
        v10 = a1;
        do
        {
          v12 = *v10++;
          v11 = v12;
          if ( v12 <= 63 && (v11 > 0x3C || ((1LL << v11) & 0x1002200000000008LL) == 0) )
            goto LABEL_3;
        }
        while ( --v9 );
      }
      if ( a4 >= 1 )
      {
        v13 = (unsigned int)a4;
        v14 = a3;
        do
        {
          v16 = *v14++;
          v15 = v16;
          if ( v16 <= 63 && (v15 > 0x3C || ((1LL << v15) & 0x1002200000000008LL) == 0) )
            goto LABEL_3;
        }
        while ( --v13 );
      }
      if ( a2 != 1 || a4 != 1 || *a1 != 3 || *a3 != 3 )
      {
LABEL_24:
        result = 0;
        goto LABEL_4;
      }
    }
  }
LABEL_3:
  result = 1;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
