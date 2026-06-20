__int64 __fastcall msm_vidc_pool_free(__int64 result, __int64 a2)
{
  __int64 v2; // x4
  __int64 v3; // x11
  _QWORD *v4; // x8
  _QWORD *v5; // x9
  __int64 v6; // x10
  __int64 v7; // x12
  _QWORD *v8; // x8
  __int64 v9; // x12

  if ( a2 )
  {
    if ( *(_QWORD *)(a2 - 8) == a2 )
    {
      v2 = *(unsigned int *)(a2 - 16);
      if ( (unsigned int)v2 < 7 )
      {
        v3 = result + 48LL * (unsigned int)v2 + 2168;
        if ( (*(_BYTE *)(a2 - 12) & 1) != 0 )
        {
          v4 = *(_QWORD **)(a2 - 24);
          *(_BYTE *)(a2 - 12) = 0;
          v5 = (_QWORD *)(a2 - 32);
          v6 = result + 48LL * (unsigned int)v2 + 2184;
          if ( *v4 == a2 - 32 && (v7 = *v5, *(_QWORD **)(*v5 + 8LL) == v5) )
          {
            *(_QWORD *)(v7 + 8) = v4;
            *v4 = v7;
          }
          else
          {
            result = _list_del_entry_valid_or_report(a2 - 32);
            a2 = v9;
          }
          v8 = *(_QWORD **)(v3 + 24);
          if ( v5 == (_QWORD *)v6 || v8 == v5 || *v8 != v6 )
          {
            return _list_add_valid_or_report(v5);
          }
          else
          {
            *(_QWORD *)(v3 + 24) = v5;
            *(_QWORD *)(a2 - 32) = v6;
            *(_QWORD *)(a2 - 24) = v8;
            *v8 = v5;
          }
        }
        else if ( result && (msm_vidc_debug & 1) != 0 )
        {
          return printk(
                   &unk_8FF99,
                   "err ",
                   result + 340,
                   "msm_vidc_pool_free",
                   *(_QWORD *)(result + 48LL * (unsigned int)v2 + 2176));
        }
      }
      else if ( result && (msm_vidc_debug & 1) != 0 )
      {
        return printk(&unk_95872, "err ", result + 340, "msm_vidc_pool_free", v2);
      }
    }
    else if ( result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        return printk(&unk_9263B, "err ", result + 340, "msm_vidc_pool_free", a2);
    }
  }
  else if ( (msm_vidc_debug & 1) != 0 )
  {
    return printk(&unk_80408, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_pool_free");
  }
  return result;
}
