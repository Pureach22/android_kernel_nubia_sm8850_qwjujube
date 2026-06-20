__int64 __fastcall os_if_dp_fill_flow_tuple(__int64 a1, int *a2)
{
  __int64 v3; // x21
  __int64 v4; // x22
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _WORD *v14; // x21
  const char *v15; // x2
  __int64 result; // x0
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v3 = *(_QWORD *)(a1 + 216);
    v4 = *(unsigned int *)(a1 + 208);
    if ( (nla_put(a1, 32769, 0, 0) & 0x80000000) != 0 || (v14 = (_WORD *)(v3 + v4)) == nullptr )
    {
      v15 = "%s: STC: Flow tuple nest start failed";
    }
    else
    {
      v17 = *a2;
      if ( (unsigned int)nla_put(a1, 1, 4, &v17) )
      {
        v15 = "%s: ipv4 src_addr nla put failed";
      }
      else
      {
        v17 = a2[4];
        if ( (unsigned int)nla_put(a1, 2, 4, &v17) )
        {
          v15 = "%s: ipv4 dst_addr nla put failed";
        }
        else
        {
          LOWORD(v17) = *((_WORD *)a2 + 16);
          if ( (unsigned int)nla_put(a1, 5, 2, &v17) )
          {
            v15 = "%s: src_port nla put failed";
          }
          else
          {
            LOWORD(v17) = *((_WORD *)a2 + 17);
            if ( (unsigned int)nla_put(a1, 6, 2, &v17) )
            {
              v15 = "%s: dst_port nla put failed";
            }
            else
            {
              LOBYTE(v17) = *((_BYTE *)a2 + 36);
              if ( !(unsigned int)nla_put(a1, 7, 1, &v17) )
              {
                result = 40;
                *v14 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v14;
                goto LABEL_9;
              }
              v15 = "%s: ip proto nla put failed";
            }
          }
        }
      }
    }
    qdf_trace_msg(0x48u, 2u, v15, v6, v7, v8, v9, v10, v11, v12, v13, "os_if_dp_fill_flow_tuple");
    result = 4294967274LL;
  }
  else
  {
    result = 44;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
