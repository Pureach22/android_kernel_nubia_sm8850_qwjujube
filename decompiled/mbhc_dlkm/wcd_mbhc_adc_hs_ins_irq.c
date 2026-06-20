__int64 __fastcall wcd_mbhc_adc_hs_ins_irq(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x1
  __int64 v6; // x8
  __int64 v7; // x1
  __int64 v8; // x1

  printk(&unk_DF5E, "wcd_mbhc_adc_hs_ins_irq");
  if ( (*(_BYTE *)(a2 + 213) & 1) != 0 )
  {
    *(_BYTE *)(a2 + 213) = 0;
  }
  else if ( *(_DWORD *)(*(_QWORD *)(a2 + 856) + 264LL) )
  {
    if ( !((unsigned __int8)(snd_soc_component_read(*(_QWORD *)(a2 + 216)) & *(_BYTE *)(*(_QWORD *)(a2 + 856) + 268LL)) >> *(_BYTE *)(*(_QWORD *)(a2 + 856) + 269LL)) )
    {
      usleep_range_state(30000, 30100, 2);
      if ( *(_DWORD *)(*(_QWORD *)(a2 + 856) + 264LL) )
      {
        if ( !((unsigned __int8)(snd_soc_component_read(*(_QWORD *)(a2 + 216))
                               & *(_BYTE *)(*(_QWORD *)(a2 + 856) + 268LL)) >> *(_BYTE *)(*(_QWORD *)(a2 + 856) + 269LL)) )
        {
          usleep_range_state(30000, 30100, 2);
          if ( *(_DWORD *)(*(_QWORD *)(a2 + 856) + 264LL) )
          {
            if ( !((unsigned __int8)(snd_soc_component_read(*(_QWORD *)(a2 + 216))
                                   & *(_BYTE *)(*(_QWORD *)(a2 + 856) + 268LL)) >> *(_BYTE *)(*(_QWORD *)(a2 + 856)
                                                                                            + 269LL)) )
            {
              usleep_range_state(30000, 30100, 2);
              if ( *(_DWORD *)(*(_QWORD *)(a2 + 856) + 264LL) )
              {
                if ( !((unsigned __int8)(snd_soc_component_read(*(_QWORD *)(a2 + 216))
                                       & *(_BYTE *)(*(_QWORD *)(a2 + 856) + 268LL)) >> *(_BYTE *)(*(_QWORD *)(a2 + 856)
                                                                                                + 269LL)) )
                {
                  usleep_range_state(30000, 30100, 2);
                  mutex_lock(a2 + 744);
                  if ( (*(_QWORD *)(a2 + 904) & 1) != 0 )
                  {
                    if ( *(_BYTE *)(a2 + 161) == 2 )
                    {
                      wcd_mbhc_hs_elec_irq((_QWORD *)a2, 0, 0);
                      v4 = *(_QWORD *)(a2 + 856);
                      v5 = *(unsigned int *)(v4 + 760);
                      if ( (_DWORD)v5 )
                        snd_soc_component_update_bits(
                          *(_QWORD *)(a2 + 216),
                          v5,
                          *(unsigned __int8 *)(v4 + 764),
                          (unsigned int)(1 << *(_BYTE *)(v4 + 765)));
                      wcd_mbhc_find_plug_and_report(a2, 1);
                    }
                    else if ( (*(_BYTE *)(*(_QWORD *)(a2 + 112) + 16LL) & 1) != 0 )
                    {
                      wcd_mbhc_hs_elec_irq((_QWORD *)a2, 0, 0);
                      v6 = *(_QWORD *)(a2 + 856);
                      v7 = *(unsigned int *)(v6 + 168);
                      if ( (_DWORD)v7 )
                      {
                        snd_soc_component_update_bits(*(_QWORD *)(a2 + 216), v7, *(unsigned __int8 *)(v6 + 172), 0);
                        v6 = *(_QWORD *)(a2 + 856);
                      }
                      v8 = *(unsigned int *)(v6 + 776);
                      if ( (_DWORD)v8 )
                        snd_soc_component_update_bits(*(_QWORD *)(a2 + 216), v8, *(unsigned __int8 *)(v6 + 780), 0);
                      *(_BYTE *)(a2 + 208) = 0;
                      *(_BYTE *)(a2 + 210) = 1;
                      *(_BYTE *)(a2 + 928) = 0;
                      wcd_mbhc_adc_detect_plug_type(a2);
                    }
                  }
                  mutex_unlock(a2 + 744);
                }
              }
            }
          }
        }
      }
    }
  }
  return 1;
}
