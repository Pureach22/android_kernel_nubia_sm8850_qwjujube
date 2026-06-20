__int64 __fastcall msm_vb2_unmap_dmabuf(__int64 result)
{
  __int64 v1; // x5
  _QWORD *v2; // x19
  __int64 v3; // x20
  _QWORD *v4; // x21
  __int64 v5; // x8
  __int64 (__fastcall *v6)(_QWORD); // x8

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
            result = print_vidc_buffer(4, (__int64)"low ", (__int64)"unmap: found ro buf", v1, (__int64)v4);
            v4[12] = v2[12];
            goto LABEL_20;
          }
        }
      }
      result = print_vidc_buffer(2, (__int64)"high", (__int64)"unmap", v1, result);
      if ( v2[13] && v2[12] )
      {
        v5 = *(_QWORD *)(v3 + 6568);
        if ( v5 )
        {
          v6 = *(__int64 (__fastcall **)(_QWORD))(v5 + 48);
          if ( v6 )
          {
            if ( *((_DWORD *)v6 - 1) != -792689463 )
              __break(0x8228u);
            result = v6(v3);
          }
        }
LABEL_20:
        v2[12] = 0;
        v2[7] = 0;
      }
    }
    else if ( (msm_vidc_debug & 1) != 0 )
    {
      return printk(&unk_83566, "err ", 0xFFFFFFFFLL, "codec", "msm_vb2_unmap_dmabuf");
    }
  }
  else if ( (msm_vidc_debug & 1) != 0 )
  {
    return printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vb2_unmap_dmabuf");
  }
  return result;
}
