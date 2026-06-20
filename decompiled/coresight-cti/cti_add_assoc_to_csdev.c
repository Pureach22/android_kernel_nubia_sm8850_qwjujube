__int64 __fastcall cti_add_assoc_to_csdev(__int64 a1)
{
  __int64 v2; // x0
  __int64 node_name; // x0
  _UNKNOWN **v4; // x23
  const char *v5; // x20
  _QWORD *i; // x24
  const char *v7; // x1
  const char *v8; // x8
  _QWORD *v9; // x25
  __int64 v10; // x9
  const char *v11; // x10
  __int64 result; // x0
  __int64 v13; // [xsp+8h] [xbp-28h] BYREF
  const char *v14; // [xsp+10h] [xbp-20h]
  __int64 v15; // [xsp+18h] [xbp-18h]
  const char *v16; // [xsp+20h] [xbp-10h]
  __int64 v17; // [xsp+28h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(&ect_mutex);
  if ( (*(_DWORD *)(a1 + 8) != 4 || *(_DWORD *)(a1 + 12) != 1) && ect_net != (_UNKNOWN *)&ect_net )
  {
    v2 = _dev_fwnode(*(_QWORD *)(a1 + 152));
    node_name = cti_plat_get_node_name(v2);
    if ( node_name )
    {
      v4 = (_UNKNOWN **)ect_net;
      if ( ect_net != (_UNKNOWN *)&ect_net )
      {
        v5 = (const char *)node_name;
        do
        {
          for ( i = *(v4 - 144); i != v4 - 144; i = (_QWORD *)*i )
          {
            v7 = (const char *)*(i - 1);
            if ( v7 && !strcmp(v5, v7) )
            {
              v8 = *(const char **)(a1 + 168);
              if ( !v8 )
                v8 = *(const char **)(a1 + 56);
              *(i - 2) = a1;
              *(i - 1) = v8;
              v9 = v4 - 146;
              v10 = (__int64)*(v4 - 146);
              v15 = a1;
              v11 = *(const char **)(v10 + 168);
              v13 = v10;
              v14 = v8;
              if ( !v11 )
                v11 = *(const char **)(v10 + 56);
              v16 = v11;
              if ( (unsigned int)coresight_add_sysfs_link(&v13) )
              {
                dev_warn(*v9 + 56LL, "Failed to set CTI sysfs link %s<=>%s\n", v14, v16);
                *(i - 2) = 0;
              }
              else
              {
                coresight_add_helper(a1, *v9);
              }
              break;
            }
          }
          v4 = (_UNKNOWN **)*v4;
        }
        while ( v4 != &ect_net );
      }
    }
  }
  result = mutex_unlock(&ect_mutex);
  _ReadStatusReg(SP_EL0);
  return result;
}
