__int64 __fastcall msm_vb2_detach_dmabuf(__int64 result)
{
  __int64 v1; // x5
  _QWORD *v2; // x19
  __int64 v3; // x20
  _QWORD *v4; // x21
  _QWORD *v5; // x22
  __int64 v6; // x8
  __int64 (__fastcall *v7)(_QWORD); // x8

  if ( result && (v1 = *(_QWORD *)(result + 16), v2 = (_QWORD *)result, v1) )
  {
    v3 = *(_QWORD *)(v1 + 320);
    if ( v3 )
    {
      if ( *(_DWORD *)(v1 + 308) == 2 && *(_DWORD *)(result + 24) == 2 )
      {
        v4 = (_QWORD *)(v1 + 2584);
        while ( 1 )
        {
          v4 = (_QWORD *)*v4;
          if ( v4 == (_QWORD *)(v1 + 2584) )
            break;
          if ( v4[11] == *(_QWORD *)(result + 88) )
          {
            result = print_vidc_buffer(4, (__int64)"low ", (__int64)"detach: found ro buf", v1, (__int64)v4);
            v5 = v2 + 13;
            v4[13] = v2[13];
            goto LABEL_19;
          }
        }
      }
      result = print_vidc_buffer(4, (__int64)"low ", (__int64)"detach", v1, result);
      v5 = v2 + 13;
      if ( v2[13] && v2[11] )
      {
        v6 = *(_QWORD *)(v3 + 6568);
        if ( v6 )
        {
          v7 = *(__int64 (__fastcall **)(_QWORD))(v6 + 32);
          if ( v7 )
          {
            if ( *((_DWORD *)v7 - 1) != 248590048 )
              __break(0x8228u);
            result = v7(v3);
          }
        }
LABEL_19:
        *v5 = 0;
      }
      v2[11] = 0;
      v2[2] = 0;
    }
    else if ( (msm_vidc_debug & 1) != 0 )
    {
      return printk(&unk_83566, "err ", 0xFFFFFFFFLL, "codec", "msm_vb2_detach_dmabuf");
    }
  }
  else if ( (msm_vidc_debug & 1) != 0 )
  {
    return printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vb2_detach_dmabuf");
  }
  return result;
}
