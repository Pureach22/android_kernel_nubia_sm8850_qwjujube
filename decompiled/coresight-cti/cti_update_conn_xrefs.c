__int64 __fastcall cti_update_conn_xrefs(__int64 result)
{
  _QWORD *v1; // x21
  _QWORD *v2; // x22
  __int64 v3; // x19
  __int64 v4; // x8
  const char *v5; // x9
  __int64 v6; // [xsp+8h] [xbp-28h] BYREF
  const char *v7; // [xsp+10h] [xbp-20h]
  __int64 v8; // [xsp+18h] [xbp-18h]
  const char *v9; // [xsp+20h] [xbp-10h]
  __int64 v10; // [xsp+28h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = (_QWORD *)(result + 24);
  v2 = *(_QWORD **)(result + 24);
  if ( v2 != (_QWORD *)(result + 24) )
  {
    v3 = result;
    do
    {
      if ( *(v2 - 2) )
      {
        v4 = *(_QWORD *)(v3 + 8);
        v6 = v4;
        v7 = (const char *)*(v2 - 1);
        v5 = *(const char **)(v4 + 168);
        v8 = *(v2 - 2);
        if ( !v5 )
          v5 = *(const char **)(v4 + 56);
        v9 = v5;
        if ( (unsigned int)coresight_add_sysfs_link(&v6) )
        {
          result = dev_warn(*(_QWORD *)(v3 + 8) + 56LL, "Failed to set CTI sysfs link %s<=>%s\n", v7, v9);
          *(v2 - 2) = 0;
        }
        else
        {
          result = coresight_add_helper(*(v2 - 2), *(_QWORD *)(v3 + 8));
        }
      }
      v2 = (_QWORD *)*v2;
    }
    while ( v2 != v1 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
