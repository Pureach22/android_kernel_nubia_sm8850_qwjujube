__int64 __fastcall swrm_get_master_port(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned __int8 a4)
{
  __int64 v4; // x8
  unsigned __int8 *v5; // x9
  __int64 v6; // x10

  *a2 = 0;
  if ( *(_BYTE *)(a1 + 15472) )
  {
    v4 = 0;
    v5 = (unsigned __int8 *)(a1 + 15503);
    v6 = 1;
    while ( v4 != 13 )
    {
      if ( *(v5 - 14) == a4 )
      {
        v6 = 0;
LABEL_23:
        *a2 = v4;
        *a3 = v5[2 * v6 - 13];
        return 0;
      }
      if ( *(v5 - 12) == a4 )
        goto LABEL_23;
      if ( *(v5 - 10) == a4 )
      {
        v6 = 2;
        goto LABEL_23;
      }
      if ( *(v5 - 8) == a4 )
      {
        v6 = 3;
        goto LABEL_23;
      }
      if ( *(v5 - 6) == a4 )
      {
        v6 = 4;
        goto LABEL_23;
      }
      if ( *(v5 - 4) == a4 )
      {
        v6 = 5;
        goto LABEL_23;
      }
      if ( *(v5 - 2) == a4 )
      {
        v6 = 6;
        goto LABEL_23;
      }
      if ( *v5 == a4 )
      {
        v6 = 7;
        goto LABEL_23;
      }
      ++v4;
      v5 += 16;
      if ( *(unsigned __int8 *)(a1 + 15472) == v4 )
        goto LABEL_13;
    }
    __break(0x5512u);
    return swrm_cleanup_disabled_port_reqs(a1);
  }
  else
  {
LABEL_13:
    if ( (unsigned int)__ratelimit(&swrm_get_master_port__rs, "swrm_get_master_port") )
      dev_err(*(_QWORD *)(a1 + 8512), "%s: port type not supported by master\n", "swrm_get_master_port");
    return 4294967274LL;
  }
}
