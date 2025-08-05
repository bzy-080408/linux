// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2025 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/backlight.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>
#include <linux/regulator/consumer.h>

#include <video/mipi_display.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct truly_r69006_5p5lg {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct regulator_bulk_data *supplies;
	struct gpio_desc *reset_gpio;
};

static const struct regulator_bulk_data truly_r69006_5p5lg_supplies[] = {
	{ .supply = "vsn" },
	{ .supply = "vsp" },
};

static inline
struct truly_r69006_5p5lg *to_truly_r69006_5p5lg(struct drm_panel *panel)
{
	return container_of(panel, struct truly_r69006_5p5lg, panel);
}

static void truly_r69006_5p5lg_reset(struct truly_r69006_5p5lg *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(5000, 6000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(5000, 6000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(5000, 6000);
}

static int truly_r69006_5p5lg_on(struct truly_r69006_5p5lg *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb3,
					 0x04, 0x10, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb4, 0x0c, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb6, 0x3b, 0xd3, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_ADDRESS_MODE, 0x98);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc, 0x04);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc1,
					 0x84, 0x00, 0x10, 0xef, 0x8b, 0xf1,
					 0xff, 0xff, 0xdf, 0x9c, 0xc5, 0x9a,
					 0x73, 0x8d, 0xad, 0x63, 0xfe, 0xff,
					 0xff, 0xcb, 0xf8, 0x01, 0x00, 0xaa,
					 0x40, 0x00, 0xc2, 0x01, 0x08, 0x00,
					 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x0d, 0xfe, 0x1f, 0x2c, 0x00, 0x00,
					 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2,
					 0x01, 0xf7, 0x80, 0x04, 0x63, 0x00,
					 0x60, 0x00, 0x01, 0x30);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3,
					 0x55, 0x01, 0x00, 0x01, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4,
					 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x02, 0x01, 0x00,
					 0x05, 0x01, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc6,
					 0x59, 0x07, 0x4a, 0x07, 0x4a, 0x01,
					 0x0e, 0x01, 0x02, 0x01, 0x02, 0x09,
					 0x15, 0x07);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc7,
					 0x00, 0x13, 0x1d, 0x29, 0x39, 0x46,
					 0x4f, 0x5c, 0x3f, 0x46, 0x51, 0x5d,
					 0x67, 0x6d, 0x7a, 0x00, 0x13, 0x1d,
					 0x29, 0x39, 0x46, 0x4f, 0x5c, 0x3f,
					 0x46, 0x51, 0x5d, 0x67, 0x6d, 0x7a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc9,
					 0x1f, 0x68, 0x1f, 0x68, 0x4c, 0x4c,
					 0xc4, 0x11);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd0,
					 0x33, 0x01, 0x91, 0x0b, 0xd9, 0x19,
					 0x19, 0x00, 0x00, 0x00, 0x19, 0x99,
					 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd3,
					 0x1b, 0x3b, 0xbb, 0xad, 0xa5, 0x33,
					 0x33, 0x33, 0x00, 0x80, 0xad, 0xa8,
					 0x5b, 0x5b, 0x33, 0x33, 0x33, 0xf7,
					 0xf2, 0x1f, 0x7d, 0x7c, 0xff, 0x0f,
					 0x99, 0x00, 0xff, 0xff);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd4, 0x57, 0x33, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd5,
					 0x66, 0x00, 0x00, 0x01, 0x33, 0x01,
					 0x33, 0x00, 0x43, 0x00, 0x43);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbe, 0x04);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf,
					 0x40, 0x10, 0x00, 0x00, 0x00, 0x00,
					 0x32, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xde,
					 0x00, 0x00, 0x3f, 0xff, 0x10);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe9, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf2, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd6, 0x01);
	mipi_dsi_dcs_set_tear_on_multi(&dsi_ctx, MIPI_DSI_DCS_TEAR_MODE_VBLANK);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce,
					 0x75, 0x40, 0x43, 0x49, 0x55, 0x62,
					 0x71, 0x82, 0x94, 0xa8, 0xb9, 0xcb,
					 0xdb, 0xe9, 0xf5, 0xfc, 0xff, 0x05,
					 0x00, 0x22, 0x05, 0x00, 0x24);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xba,
					 0x03, 0x70, 0x81, 0x20, 0x45, 0xb4);
	mipi_dsi_dcs_set_display_brightness_multi(&dsi_ctx, 0x0000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x11, 0x00);
	mipi_dsi_msleep(&dsi_ctx, 120);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x29, 0x00);
	mipi_dsi_msleep(&dsi_ctx, 26);

	return dsi_ctx.accum_err;
}

static int truly_r69006_5p5lg_off(struct truly_r69006_5p5lg *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_usleep_range(&dsi_ctx, 10000, 11000);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd3,
					 0x13, 0x3b, 0xbb, 0xa5, 0xa5, 0x33,
					 0x33, 0x33, 0x00, 0x80, 0xa4, 0xa8,
					 0x37, 0x33, 0x33, 0x33, 0x33, 0xf7,
					 0xf2, 0x1f, 0x7d, 0x7c, 0xff, 0x0f,
					 0x99, 0x00, 0xff, 0xff);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 90);

	return dsi_ctx.accum_err;
}

static int truly_r69006_5p5lg_prepare(struct drm_panel *panel)
{
	struct truly_r69006_5p5lg *ctx = to_truly_r69006_5p5lg(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = regulator_bulk_enable(ARRAY_SIZE(truly_r69006_5p5lg_supplies), ctx->supplies);
	if (ret < 0) {
		dev_err(dev, "Failed to enable regulators: %d\n", ret);
		return ret;
	}

	truly_r69006_5p5lg_reset(ctx);

	ret = truly_r69006_5p5lg_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		regulator_bulk_disable(ARRAY_SIZE(truly_r69006_5p5lg_supplies), ctx->supplies);
		return ret;
	}

	return 0;
}

static int truly_r69006_5p5lg_unprepare(struct drm_panel *panel)
{
	struct truly_r69006_5p5lg *ctx = to_truly_r69006_5p5lg(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = truly_r69006_5p5lg_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	regulator_bulk_disable(ARRAY_SIZE(truly_r69006_5p5lg_supplies), ctx->supplies);

	return 0;
}

static const struct drm_display_mode truly_r69006_5p5lg_mode = {
	.clock = (1080 + 40 + 8 + 20) * (1920 + 8 + 2 + 10) * 60 / 1000,
	.hdisplay = 1080,
	.hsync_start = 1080 + 40,
	.hsync_end = 1080 + 40 + 8,
	.htotal = 1080 + 40 + 8 + 20,
	.vdisplay = 1920,
	.vsync_start = 1920 + 8,
	.vsync_end = 1920 + 8 + 2,
	.vtotal = 1920 + 8 + 2 + 10,
	.width_mm = 69,
	.height_mm = 122,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int truly_r69006_5p5lg_get_modes(struct drm_panel *panel,
					struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &truly_r69006_5p5lg_mode);
}

static const struct drm_panel_funcs truly_r69006_5p5lg_panel_funcs = {
	.prepare = truly_r69006_5p5lg_prepare,
	.unprepare = truly_r69006_5p5lg_unprepare,
	.get_modes = truly_r69006_5p5lg_get_modes,
};

static int truly_r69006_5p5lg_bl_update_status(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness = backlight_get_brightness(bl);
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_set_display_brightness_large(dsi, brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return 0;
}

// TODO: Check if /sys/class/backlight/.../actual_brightness actually returns
// correct values. If not, remove this function.
static int truly_r69006_5p5lg_bl_get_brightness(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness;
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_get_display_brightness_large(dsi, &brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return brightness;
}

static const struct backlight_ops truly_r69006_5p5lg_bl_ops = {
	.update_status = truly_r69006_5p5lg_bl_update_status,
	.get_brightness = truly_r69006_5p5lg_bl_get_brightness,
};

static struct backlight_device *
truly_r69006_5p5lg_create_backlight(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	const struct backlight_properties props = {
		.type = BACKLIGHT_RAW,
		.brightness = 4095,
		.max_brightness = 4095,
	};

	return devm_backlight_device_register(dev, dev_name(dev), dev, dsi,
					      &truly_r69006_5p5lg_bl_ops, &props);
}

static int truly_r69006_5p5lg_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct truly_r69006_5p5lg *ctx;
	int ret;

	ctx = devm_drm_panel_alloc(dev, struct truly_r69006_5p5lg, panel,
				   &truly_r69006_5p5lg_panel_funcs,
				   DRM_MODE_CONNECTOR_DSI);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);

	ret = devm_regulator_bulk_get_const(dev,
					    ARRAY_SIZE(truly_r69006_5p5lg_supplies),
					    truly_r69006_5p5lg_supplies,
					    &ctx->supplies);
	if (ret < 0)
		return ret;

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO_BURST | MIPI_DSI_MODE_VIDEO_HSE |
			  MIPI_DSI_MODE_NO_EOT_PACKET |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS;

	ctx->panel.prepare_prev_first = true;

	ctx->panel.backlight = truly_r69006_5p5lg_create_backlight(dsi);
	if (IS_ERR(ctx->panel.backlight))
		return dev_err_probe(dev, PTR_ERR(ctx->panel.backlight),
				     "Failed to create backlight\n");

	drm_panel_add(&ctx->panel);

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		drm_panel_remove(&ctx->panel);
		return dev_err_probe(dev, ret, "Failed to attach to DSI host\n");
	}

	return 0;
}

static void truly_r69006_5p5lg_remove(struct mipi_dsi_device *dsi)
{
	struct truly_r69006_5p5lg *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id truly_r69006_5p5lg_of_match[] = {
	{ .compatible = "leeco,s2-r69006-lg" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, truly_r69006_5p5lg_of_match);

static struct mipi_dsi_driver truly_r69006_5p5lg_driver = {
	.probe = truly_r69006_5p5lg_probe,
	.remove = truly_r69006_5p5lg_remove,
	.driver = {
		.name = "panel-truly-r69006-5p5lg",
		.of_match_table = truly_r69006_5p5lg_of_match,
	},
};
module_mipi_dsi_driver(truly_r69006_5p5lg_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for truly r69006 fhd cmd dsi panel");
MODULE_LICENSE("GPL");
